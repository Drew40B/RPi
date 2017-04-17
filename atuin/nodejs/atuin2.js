// http://unipad.digitalray.co.jp/docs/#messages_receive

var io = require('socket.io')({
transports: ['websocket'],
});

var port = 6666;
io.attach(port);

io.on('connection', function(socket){
    socket.on("disconnect", function () {
      console.log("offline id: " + socket.id);
      socket.broadcast.emit("offline", { id: socket.id });
      padDisconnect(socket.id);
      });
    socket.on("/hello",function(obj){
      console.log("receive hello");
      padConnect(socket.id);
      socket.emit("/config/type", { value: 1 });

      });
    socket.on("/touch/start" ,function(obj){ padState(socket.id,"start",obj); });
    socket.on("/touch/end"    ,function(obj){ padState(socket.id,"end",obj); });
 
});

console.log("Listening on port: " + port);
	
var exec = require('child_process').exec;

function puts(error, stdout, stderr)
 { 
	 console.log(stdout)
 }
 
function RobotDirection(dir)
{
	exec("/home/pi/nodejs/atuin/bin/atuin " + dir,puts);
}	
	

function padState(index,action, obj){
  console.log( index + ":" + action + " " +obj);
  io.sockets.emit("padstate", {index:index,value: obj});
  
  if (action == "end"){
	RobotDirection("Stop");
  } else if (obj == "Up"){
	RobotDirection("Forward");
  } else if (obj == "Left") {
	  RobotDirection("Left");
  } else if (obj == "Right"){
	  RobotDirection("Right");
  } else if(obj == "Down"){
		RobotDirection("Reverse");
  } else
     RobotDirection("Stop");

}

function padConnect(id){
  console.log("padconnct" + id);
  io.sockets.emit("padconnect", {id:id});
}

function padDisconnect(id){

  console.log("paddisconnct" + id);
  io.sockets.emit("paddisconnect", {id:id});
  
  RobotDirection("Stop");

}

exec("/home/pi/nodejs/atuin/bin/atuin Stop",puts);

