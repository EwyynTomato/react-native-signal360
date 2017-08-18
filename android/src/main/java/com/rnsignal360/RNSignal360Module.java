
package com.rnsignal360;

import android.app.Activity;
import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.UiThreadUtil;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.RCTNativeAppEventEmitter;
import com.signal360.sdk.core.Signal;
import com.signal360.sdk.core.SignalClient;
import com.signal360.sdk.core.SignalSdkStatus;
import com.signal360.sdk.core.objects.SignalActivation;
import com.signal360.sdk.core.objects.SignalActivationRule;
import com.signal360.sdk.core.objects.SignalCodeHeard;
import com.signal360.sdk.core.objects.SignalLocation;

import java.util.List;
import java.util.Map;

public class RNSignal360Module extends ReactContextBaseJavaModule implements SignalClient {
    private String guid = "DEFAULT";
    private String askPermissionString = "LOCATION and MICROPHONE permission is required";

    private static final String EMITTED_EVENT_NAME = "RNSignal360Event"; //If you change this, remember to also change it in index.js

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

    @ReactMethod
    public void setGuid(String guid) {
        this.guid = guid;
    }

    @ReactMethod
    public void setAskPermissionString(String askPermissionString) {
        this.askPermissionString = askPermissionString;
    }

    @ReactMethod
    public void start() {
        Signal.get().initialize(reactContext.getApplicationContext(), RNSignal360Module.this, guid);
        Signal.get().start();

        Activity activity = reactContext.getCurrentActivity();

        //- Check com.signal360.sdk.core.internal.SignalInternal > requestPermissions to customize request permission
        Signal.get().requestPermissions(activity, askPermissionString);
        Signal.get().onActivityResume(activity);
    }

    @Override
    public Boolean didHearCode(Signal signal, SignalCodeHeard codeHeard) {
        //Call JS Callback on frontend with signal data
        //React-native's Callback object can only be invoked ONCE, so we use RCTNativeAppEventEmitter instead
        WritableMap map = Arguments.createMap();
        map.putString("signalType", codeHeard.getSignalType());
        map.putDouble("beaconCode", codeHeard.getBeaconCode());
        RCTNativeAppEventEmitter eventEmitter = getReactApplicationContext().getJSModule(RCTNativeAppEventEmitter.class);
        eventEmitter.emit(EMITTED_EVENT_NAME, map);
        return true;
    }

    @Override
    public void didReceiveActivations(Signal signal, List<SignalActivation> list) {

    }

    @Override
    public void cacheOfflineContent(Signal signal, List<SignalActivationRule> list) {

    }

    @Override
    public void geoFenceEntered(SignalLocation signalLocation) {

    }

    @Override
    public void geoFenceExited(SignalLocation signalLocation) {

    }

    @Override
    public void geoFencesUpdated(List<SignalLocation> list) {

    }

    @Override
    public void didStatusChange(SignalSdkStatus signalSdkStatus) {

    }

    @Override
    public void didCompleteRegistration(boolean b) {

    }

    @Override
    public void didUpdateConfiguration(boolean b) {

    }

    @Override
    public void didUpdateUserData(boolean b) {

    }

    @Override
    public Map<String, String> getTagsForCode(SignalCodeHeard signalCodeHeard, Map<String, String> map) {
        return null;
    }

    @Override
    public List<String> getBeaconTagsForConfig() {
        return null;
    }
}