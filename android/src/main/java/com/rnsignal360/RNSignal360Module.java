
package com.rnsignal360;

import android.app.Activity;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.signal360.sdk.core.Signal;
import com.signal360.sdk.core.internal.SignalInternal;

public class RNSignal360Module extends ReactContextBaseJavaModule {
    private String guid = "DEFAULT";
    private String askPermissionString = "LOCATION and MICROPHONE permission is required";

    private RNSignal360Client rnSignal360Client;
    private boolean isInitialized = false;

    private final ReactApplicationContext reactContext;

    public RNSignal360Module(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "RNSignal360";
    }

    public static void onRequestPermissionsResult(Activity activity, int requestCode, String permissions[], int[] grantResults) {
        if (grantResults[0] == -1 || grantResults[1] == -1) {
            //- permission is not granted, stop Signal from listening
            // (note that dismissing alert window won't stop Signal Service, customize requestPermission to handle this)
            Signal.get().stop();
            Signal.get().clear();
        }

        Signal.get().onRequestPermissionsResult(activity, requestCode, permissions, grantResults);
    }

    private Activity getActivity() {
        return reactContext.getCurrentActivity();
    }

    @ReactMethod
    public void setGuid(String guid) {
        this.guid = guid;
    }

    @ReactMethod
    public void setAskPermissionString(String askPermissionString) {
        this.askPermissionString = askPermissionString;
    }

    public void initialize() {
        if (!this.isInitialized) {
            rnSignal360Client = new RNSignal360Client(reactContext);
            Signal.get().initialize(reactContext.getApplicationContext(), rnSignal360Client, guid);
            Signal.get().start();
            isInitialized = true;
        }
    }

    @ReactMethod
    public void start() {
        this.initialize();

        Activity activity = getActivity();

        //- Check com.signal360.sdk.core.internal.SignalInternal > requestPermissions to customize request permission
        SignalInternal.getInternal().setUseBluetooth(true);
        Signal.get().requestPermissions(activity, askPermissionString);
        Signal.get().onActivityResume(activity);
    }

    @ReactMethod
    public void stop() {
        Activity activity = getActivity();

        Signal.get().onActivityPause(activity);
    }
}