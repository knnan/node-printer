var printer = require("../lib");

printer.printDirect({
	data: "print from Node.JS buffer",
	type: 'RAW',
	formname: 'ucform',
	length: 500,
	width: 500,
	success: function (jobID)
	{
		console.log("sent to printer with ID: " + jobID);
	},
	error: function (err) { console.log(err); }
});
