var initialized = false;

var options = {};

Pebble.addEventListener("ready", function() {
	console.log("ready called!");
	initialized = true;
});

Pebble.addEventListener("showConfiguration", function() {
	// on call, make sure options represents latest persistant data
	options = JSON.parse(localStorage.getItem("settings"));
	
	// make a console entry and open the website
	console.log("showing configuration");
	Pebble.openURL('http://www.domwakeling.com/pebble/segmented/segmented_config_1_4.html?'+encodeURIComponent(JSON.stringify(options)));
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
		
		// make a dictionary with the "date" function
		var dateshowing = options.datevisible;
		console.log("dateshowing: " + dateshowing);
		
		var dictionary = {
			'KEY_SHOW_DATE' : dateshowing
		};
		
		// send it to the watch
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
