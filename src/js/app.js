var initialized = false;

var options = {};

Pebble.addEventListener("ready", function() {
	console.log("Segmented: ready called!");
	initialized = true;
});

Pebble.addEventListener("showConfiguration", function() {
	// on call, make sure options represents latest persistant data
	options = JSON.parse(localStorage.getItem("settings"));
	if(options) { 
		options.watchType = getWatchVersion();
	} else { 
		options = {'watchType' : getWatchVersion()};
	}
	console.log("Options being sent= " + JSON.stringify(options));
	
	// get the watch type, make a console entry and open the website
	var watch_type = getWatchVersion();
	
	console.log("showing configuration for watchtype" + watch_type);
	Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_2_1_comb.html?'+encodeURIComponent(JSON.stringify(options)));	
	
	/*if(watch_type >= 3) {
		console.log("showing configuration for basalt");
		Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_2_1_col.html?'+encodeURIComponent(JSON.stringify(options)));
	} else {
		console.log("showing configuration for aplite");
		Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_2_1_bw.html?'+encodeURIComponent(JSON.stringify(options)));
	}*/
});

Pebble.addEventListener("webviewclosed", function(e) {
	// make a console entry
	console.log("configuration closed");
	console.log("event info");
	console.log(e.response);
		
	try {
		// set options based on the return data, and send to persistant storage
		options = JSON.parse(decodeURIComponent(e.response));
		localStorage.setItem("settings", JSON.stringify(options));
		
		// log the returned info
		console.log("Options received = " + JSON.stringify(options));
		
		// we want to make a dictionary from the available information, so get the values as variables ...
		var dateshowing;
		if( options.datevisible == "checked") {
			dateshowing = "on";
		} else {
			dateshowing = "off";
		}
		console.log("dateshowing: " + dateshowing);
		
		var selectedcolour = "FFFFFF"; // will default to white; not used in Aplite, but sent to avoid addl code in main.c
		try {
			selectedcolour = options.digit_colour.toString().slice(2);
			console.log("colour selected: " + selectedcolour);
		}
		catch(err) {
			console.log("no colour selection received, setting to white");
		}
		
		var bluetoothshowing;
		if( options.showbluetooth == "checked") {
			bluetoothshowing = "on";
		} else {
			bluetoothshowing = "off";
		}
		console.log("bluetoothshowing: " + bluetoothshowing);
		
		// ... then build a dictionary ...
		var dictionary = {
			'SHOW_DATE' : dateshowing,
			'DIGIT_COLOUR' : selectedcolour,
			'SHOW_BLUETOOTH' : bluetoothshowing
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
		
	}	
	// if we hit an error in the above ...
	catch(err) {
		// ... log that configuation was cancelled and the error that caused it
		console.log("Cancelled due to error: " + err);
	}
});

function getWatchVersion() {
	// 1 = Pebble OG
	// 2 = Pebble Steel
	// 3 = Pebble Time
	// 3 = Pebble Basalt Emulator (currently Pebble Time)
	// 4 = Pebble Time Steel
	// 5 = Pebble Time Round
	// 5 = Pebble Time Emulator
	
	var watch_version = 1;
 
	if(Pebble.getActiveWatchInfo) {
		// Available for use!
		var watch_name = Pebble.getActiveWatchInfo().model;
 		if (watch_name.indexOf("pebble_time_round") >= 0) {
			watch_version = 5;
		} else if (watch_name.indexOf("qemu_platform_chalk") >= 0) {
			watch_version = 5;
		} else if (watch_name.indexOf("pebble_time_steel") >= 0) {
			watch_version = 4;
		} else if (watch_name.indexOf("pebble_time") >= 0) {
			watch_version = 3;
		} else if (watch_name.indexOf("qemu_platform_basalt") >= 0) {
			watch_version = 3;
		} else if (watch_name.indexOf("pebble_steel") >= 0) {
			watch_version = 2;
		}
		console.log("watch name " + watch_name + ", watch version " + watch_version);
	}
	return watch_version;
}
