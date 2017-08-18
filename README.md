- Add the following in Android MainActivity.java:

  ```
      @Override
    public void onRequestPermissionsResult(int requestCode,String permissions[], int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        RNSignal360Module.onRequestPermissionsResult(this, requestCode, permissions, grantResults);
    }
  ```