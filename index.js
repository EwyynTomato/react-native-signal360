import { NativeModules, NativeEventEmitter } from 'react-native';

const { RNSignal360 } = NativeModules;

const Signal360 = {
	addEventListener: function(callback) {
        new NativeEventEmitter(RNSignal360).addListener('RNSignal360Event', (data) => {
        	console.log(`RNSignal360: emitted data: ${JSON.stringify(data)}`);
            callback(data);
        });
	},

	/**
	 * Set Signal360 GUID, this is "DEFAULT" by default.
	 */
	setGuid: function(guid) {
		RNSignal360.setGuid(guid);
	},

	/**
	 * Set the text for Ask Permission modal window
	 */
	setAskPermissionString: function(text) {
		RNSignal360.setAskPermissionString(text);
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
