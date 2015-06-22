var initialized = false;

var options = {};

Pebble.addEventListener("ready", function() {
	console.log("Segmented: ready called!");
	initialized = true;
});

Pebble.addEventListener("showConfiguration", function() {
	// on call, make sure options represents latest persistant data
	options = JSON.parse(localStorage.getItem("settings"));
	console.log("Options being sent= " + JSON.stringify(options));
	
	// get the watch type, make a console entry and open the website
	var watch_type = getWatchVersion();
	
	if(watch_type >= 3) {
		console.log("showing configuration for basalt");
		Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_1_6_col.html?'+encodeURIComponent(JSON.stringify(options)));
	} else {
		console.log("showing configuration for aplite");
		Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_1_6_bw.html?'+encodeURIComponent(JSON.stringify(options)));
	}
});

Pebble.addEventListener("webviewclosed", function(e) {
	// make a console entry
	console.log("configuration closed");

	//Using primitive JSON validity and non-empty check
	if (e.response.charAt(0) == "{" && e.response.slice(-1) == "}" && e.response.length > 5) {
		
		// set options based on the return data, and send to persistant storage
		options = JSON.parse(decodeURIComponent(e.response));
		localStorage.setItem("settings", JSON.stringify(options));
		
		// log the returned info
		console.log("Options = " + JSON.stringify(options));
		
		// we want to make a dictionary from the available information, so get the values as variables ...
		var dateshowing = options.datevisible;
		console.log("dateshowing: " + dateshowing);
		
		var selectedcolour = options.basalt_colors;
		console.log("colour selected: " + selectedcolour);
		
		var bluetoothshowing = options.showbluetooth;
		console.log("bluetoothshowing: " + bluetoothshowing);
		
		// ... then build a dictionary ...
		var dictionary = {
			'KEY_SHOW_DATE' : dateshowing,
			'KEY_DIGIT_COLOUR' : selectedcolour,
			'KEY_SHOW_BLUETOOTH' : bluetoothshowing
		};
		
		// ... and send it to the watch
		Pebble.sendAppMessage(dictionary,
			function(e) {
				console.log("Configuation successfuly sent to Pebble");
			},
			function(e) {
				console.log("Error sending configuration to Pebble");
			}
		);
		
	} else {
		// if we failed the test, log that configuation was cancelled
		console.log("Cancelled");
	}
});

function getWatchVersion() {
	// 1 = Pebble OG
	// 2 = Pebble Steel
	// 3 = Pebble Time
	// 3 = Pebble Basalt Emulator (currently Pebble Time)
	// 4 = Pebble Time Steel
	
	var watch_version = 1;
 
	if(Pebble.getActiveWatchInfo) {
		// Available for use!
		var watch_name = Pebble.getActiveWatchInfo().model;
 
		if (watch_name.indexOf("pebble_time_steel") >= 0) {
			watch_version = 4;
		} else if (watch_name.indexOf("pebble_time") >= 0) {
			watch_version = 3;
		} else if (watch_name.indexOf("qemu_platform_basalt") >= 0) {
			watch_version = 3;
		} else if (watch_name.indexOf("pebble_steel") >= 0) {
			watch_version = 2;
		}
	}
	
	return watch_version;
}
