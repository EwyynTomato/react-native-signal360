
package com.rnsignal360;

import android.app.Activity;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.signal360.sdk.core.Signal;
import com.signal360.sdk.core.internal.SignalInternal;

public class RNSignal360Module extends ReactContextBaseJavaModule {
    private String guid = "DEFAULT";

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
        // If request is cancelled, the result arrays are empty.
        if (grantResults.length > 0) {
            Signal.get().onRequestPermissionsResult(activity, requestCode, permissions, grantResults);
        }
    }

    private Activity getActivity() {
        return reactContext.getCurrentActivity();
    }

    @ReactMethod
    public void setGuid(String guid) {
        this.guid = guid;
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
        Signal.get().onActivityResume(activity);
    }

    @ReactMethod
    public void stop() {
        Activity activity = getActivity();

        Signal.get().onActivityPause(activity);
    }
}