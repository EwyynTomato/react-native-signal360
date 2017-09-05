- Add the following in Android MainActivity.java:

  ```
      @Override
    public void onRequestPermissionsResult(int requestCode,String permissions[], int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        RNSignal360Module.onRequestPermissionsResult(this, requestCode, permissions, grantResults);
    }
  ```

- Add the following key value pairs to iOS Info.plist:

```
  <key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
  <string>We would like to use your location to inform you of stores available nearby</string>
  <key>NSLocationWhenInUseUsageDescription</key>
  <string>We would like to use your location to inform you of stores available nearby</string>
  <key>NSMicrophoneUsageDescription</key>
  <string>We would like to use your location to inform you of stores available nearby</string>
```