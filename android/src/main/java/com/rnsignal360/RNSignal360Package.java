
package com.rnsignal360;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import com.facebook.react.ReactPackage;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.uimanager.ViewManager;
import com.facebook.react.bridge.JavaScriptModule;
public class RNSignal360Package implements ReactPackage {
    public RNSignal360Module RNSignal360Module;

    @Override
    public List<NativeModule> createNativeModules(ReactApplicationContext reactContext) {
        RNSignal360Module = new RNSignal360Module(reactContext);
      return Arrays.<NativeModule>asList(RNSignal360Module);
    }

    //Deprecated in RN 0.47
    public List<Class<? extends JavaScriptModule>> createJSModules() {
      return Collections.emptyList();
    }

    @Override
    public List<ViewManager> createViewManagers(ReactApplicationContext reactContext) {
      return Collections.emptyList();
    }
}