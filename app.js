var serialport = require("serialport");
var SerialPort = serialport.SerialPort;
var portName = process.argv[2];

var myPort =new SerialPort(portName,{
    baudrate:11500,
    parser:serialport.parsers.Readline("\r\n")
})

myPort.on('open', onOpen);
myPort.on('data', onData);

function onOpen(){
    console.log("OPen connection established");
}

function onData(data){
    console.log("on Data" + data);
}
