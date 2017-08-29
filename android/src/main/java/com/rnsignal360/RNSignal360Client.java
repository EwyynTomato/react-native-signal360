package com.rnsignal360;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.RCTNativeAppEventEmitter;
import com.signal360.sdk.core.Signal;
import com.signal360.sdk.core.SignalClient;
import com.signal360.sdk.core.SignalSdkStatus;
import com.signal360.sdk.core.objects.SignalActivation;
import com.signal360.sdk.core.objects.SignalActivationRule;
import com.signal360.sdk.core.objects.SignalCodeHeard;
import com.signal360.sdk.core.objects.SignalLocation;

import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class RNSignal360Client implements SignalClient {
    private static final String EMITTED_EVENT_NAME = "RNSignal360Event"; //If you change this, remember to also change it in index.js

    private ReactApplicationContext reactContext;

    public RNSignal360Client(ReactApplicationContext reactContext) {
        this.reactContext = reactContext;
    }

    /**
     * Call JS Callback on frontend with signal data
     * React-native's Callback object can only be invoked ONCE, so we use RCTNativeAppEventEmitter instead
     * @param codeHeard
     */
    private void emitEvent(SignalCodeHeard codeHeard) {
        WritableMap map = Arguments.createMap();
        map.putString("signalType", codeHeard.getSignalType());
        map.putDouble("beaconCode", codeHeard.getBeaconCode());
        RCTNativeAppEventEmitter eventEmitter = reactContext.getJSModule(RCTNativeAppEventEmitter.class);
        eventEmitter.emit(EMITTED_EVENT_NAME, map);
    }

    @Override
    public Boolean didHearCode(Signal signal, SignalCodeHeard codeHeard) {
        this.emitEvent(codeHeard);
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
