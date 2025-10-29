# ESP32 Blynk + DHT22 (PlatformIO / Wokwi)

This project contains an ESP32 sketch that reads a DHT22 sensor and sends temperature and humidity to Blynk. It includes a Wokwi diagram for simulation.

Files added:
- `platformio.ini` — PlatformIO project configuration (ESP32, Arduino framework, lib dependencies)
- `wokwi.toml` — Wokwi config to point to PlatformIO build output
- `src/main.ino` — Sketch (Blynk + DHT22, LED control on V3)
- `diagram.json` — Wokwi parts and wiring for simulation

How to build locally (PlatformIO)
1. Install PlatformIO (VS Code extension) and open this folder in VS Code.
2. From the PlatformIO side bar click Build or run from command line:

```cmd
cd "c:\Users\HP\OneDrive\Desktop\Embedded assignment\test"
platformio run
```

Note: On first build PlatformIO will download toolchains and libraries specified in `platformio.ini`.

How to run in Wokwi
1. Go to https://wokwi.com and create a new project or import the `diagram.json` content into Wokwi.
2. Wokwi will simulate the project and use the `wokwi.toml` file to find the firmware path if you upload a prebuilt firmware, or you can paste the sketch into Wokwi's editor.

Blynk
- The sketch uses a Blynk template and auth token already defined in `src/main.ino`.
- Adjust `ssid` and `pass` in `src/main.ino` if you want to connect to a real Wi-Fi network.

Limitations
- I could not run a PlatformIO build inside this environment. Run `platformio run` locally to compile and verify firmware.

If you want, I can:
- Attempt a local PlatformIO build here (if you want me to run `platformio run` remotely) or
- Add a `.vscode/tasks.json` to make building from VS Code one-click.
