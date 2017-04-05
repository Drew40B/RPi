// HTTP module
var http = require('http'),
    HttpDispatcher = require('httpdispatcher'),
    dispatcher  = new HttpDispatcher(),
    fs = require('fs'),
    url = require('url');


// port to listen on
const PORT = 8080;

var exec = require('child_process').exec;

//For all your static (js/css/images/etc.) set the directory name (relative path).
dispatcher.setStatic('/resources');
dispatcher.setStaticDirname('resources');


function puts(error, stdout, stderr)
 { 
	 console.log(stdout)
 }
 
function RobotDirection(req, res,dir)
{
	exec("/home/pi/nodejs/atuin/bin/atuin " + dir,puts);
	
	res.writeHead(200, {'Content-Type': 'text/html'});
	var html = "<html><head><body>";
		html += '<p>GET request | Robot ' + dir +'</p>';
		html += "</body></html>";
  res.end(html);
  

}

// GET request
dispatcher.onGet("/robot/left", function(req,res){RobotDirection(req,res,"Left")});
dispatcher.onGet("/robot/right", function(req,res){RobotDirection(req,res,"Right")});
dispatcher.onGet("/robot/stop", function(req,res){RobotDirection(req,res,"Stop")});
dispatcher.onGet("/robot/forward", function(req,res){RobotDirection(req,res,"Forward")});
dispatcher.onGet("/robot/reverse", function(req,res){RobotDirection(req,res,"Reverse")});

dispatcher.onGet("/robot.html", function(req,res) 
{
	res.writeHead(302, {'Location': '/resources/robot.html'});
	res.end();
      
});
	
exec("/home/pi/nodejs/atuin/bin/atuin Stop",puts);


// missing route or resource
dispatcher.onError(function(req, res) {
  res.writeHead(404);
  res.end('404 - Page Not Found');
});


// handle requests
function handleRequest(req, res) {
  try {
    console.log("Request -> %s",req.url)
    
    if(url.parse(req.url).pathname == '/'){
		res.writeHead(302, {'Location': '/resources/robot.html'});
		res.end();
		return;
	}
    // disptach route
    dispatcher.dispatch(req, res);
  } catch (err) {
    console.log(err);
  }
}

// create server using request handler
var server = http.createServer(handleRequest);

// start the server
server.listen(PORT, function() {

  // callback for listening
  console.log("Node server listening on: http://localhost:%s", PORT);
});


