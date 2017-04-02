/**
 *  Put code in server.js
 *  
 *  ------------------------------------
 * 
 *  To run server:
 * 
 *  $ node server.js
 * 
 *  To open webpage:
 * 
 *  $ open http://localhost:8080 
 * 
 *  ------------------------------------
 * 
 *  To install httpdispatcher
 * 
 *  $ npm init
 *  $ npm install httpdispatcher
 */ 

/*
    GET /page1 => 'GET request | Page 1'
    POST /page2 => 'POST request | Post 2'
    GET /page3 => 404
    GET /resources/images-that-exists.png => Image resource
    GET /resources/images-that-does-not-exists.png => 404
*/

// HTTP module
var http = require('http'),
   HttpDispatcher = require('httpdispatcher'),
 dispatcher     = new HttpDispatcher(),
  fs = require('fs'),
  url = require('url');

// port to listen on
const PORT = 8080;

//For all your static (js/css/images/etc.) set the directory name (relative path).
dispatcher.setStatic('/resources');
dispatcher.setStaticDirname('static');

// GET request
dispatcher.onGet("/page1", function(req, res) {
  res.writeHead(200, {
    'Content-Type': 'text/html'
  });
  var html = "<html><head><body>";
  html += '<p>GET request | Page 1 </p>';
  html += '<p><img src="/resources/image-that-exists.jpg"></p>';
  html += "</body></html>";
  res.end(html);
});

// GET request
dispatcher.onGet("/ls", function(req, res) {
  res.writeHead(200, {
    'Content-Type': 'text/html'
  });

 var html = "<html><head><body>";
  html += '<p>LS</p>';
  html += '<p><img src="/resources/image-that-exists.jpg"></p>';
  html += "</body></html>";
  res.end(html);
 //var sys = require('sys')
var exec = require('child_process').exec;

function puts(error, stdout, stderr)
 { console.log(stdout)
 }
exec("ls -la", puts);
});

// POST request
dispatcher.onPost("/post2", function(req, res) {
  res.writeHead(200, {
    'Content-Type': 'text/plain'
  });
  res.end('POST request | Post 2');
});

// any url
dispatcher.beforeFilter(/\//, function(req, res, chain) { //any url
  console.log("Filter - Before");
  var request = url.parse(req.url, true);
  var action = request.pathname;

  console.log(action);

  if (action == '/resources/image-that-exists.jpg') {
    var stats = fs.statSync('.' + action);
    var fileSizeInBytes = stats["size"];
    var img = fs.readFileSync('.' + action);
    res.writeHead(200, {
      'Content-Type': 'image/jpg',
      'Content-Length': fileSizeInBytes
    });
    res.end(img, 'binary');
  }

  chain.next(req, res, chain);
});

// any url
dispatcher.afterFilter(/\//, function(req, res, chain) {
  console.log("Filter - After");
  chain.next(req, res, chain);
});

// missing route or resource
dispatcher.onError(function(req, res) {
  res.writeHead(404);
  res.end('404 - Page Not Found');
});

// handle requests
function handleRequest(request, response) {
  try {
    console.log(request.url);
    // disptach route
    dispatcher.dispatch(request, response);
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


