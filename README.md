# PacketCommand

Send TCP packets via Ethernet from STM32F7 to remotely control the server system.

## Process

I2S audio data is sent via an established TCP connection from the client (STM32F7) to the server (Desktop). The server then uses voice recognition software to decode I2S data and access the CLI to perform various commands.

Rust-based companion-app: https://github.com/bsgursta/PacketCommand_app