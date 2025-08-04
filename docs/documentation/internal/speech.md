# SpeechSynthesizer

## Windows
* example [wsay](https://github.com/p-groarke/wsay)

## macOS

* api : [NSSpeechSynthesizer](https://developer.apple.com/documentation/appkit/nsspeechsynthesizer)
* command: `say`
* Get voice list : `say -v \?`
* Speech text: `say "Hello, World"`
* Speech text with specified voice : `say -v "Alex" "Hello, World"`
* Speech specified file and voice : `say -v "Alex" -f hello_world.txt`
* Speech text to specified output file : `say -o hello_world.aiff  "Hello, World"`

## Linux

* example [say](https://github.com/brailcom/speechd/blob/master/src/clients/say/say.c)