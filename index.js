import { NativeModules, NativeEventEmitter } from 'react-native';
import codeHeardQueue from './src/codeHeardQueue';

const { RNSignal360 } = NativeModules;

const Signal360 = {
	addEventListener: function(callback) {
        new NativeEventEmitter(RNSignal360).addListener('RNSignal360Event', (data) => {
            let beaconCode = data.beaconCode;
            if (codeHeardQueue.shouldCodeInvokeCallback(beaconCode)) {
                callback(data);
            }
            codeHeardQueue.heardCode(beaconCode);
        });
	},

	/**
	 * Set Signal360 GUID, this is "DEFAULT" by default.
	 */
	setGuid: function(guid) {
		RNSignal360.setGuid(guid);
	},

    /**
     * Start Signal360 service to listen to Sonic device
     */
    start: function() {
        RNSignal360.start();
    },

    stop: function() {
        RNSignal360.stop();
    },
};

export default Signal360;
