# OwlBOT_GPT

A collection of ESP32 example projects, sketches and resources demonstrating voice interaction with ChatGPT, speech-to-text and text-to-speech on ESP32-based boards. The repository contains sample Arduino sketches for an animatronic owl, audio I/O examples, and multiple ChatGPT voice assistant demos.

## Repository structure

- `Animatronic_Owl_Sample/` — Arduino sketch for an animatronic owl example.
- `AudioOutpu_ChatGPT/` — sample project for audio output integration.
- `ChatGPT Voice Assistant/`
	- `ESP32_Speech_to_Text/` — speech-to-text client and examples (I2S, audio handling, CloudSpeech client).
	- `ESP32_Text_to_Speech/` — text-to-speech examples for ESP32.
- `ChatGPT_ESP32_DemoCode/` — single-file demo sketch integrating ChatGPT features.
- `ESP32_TextToSpeech_SampleCode/` — additional TTS sample code.
- `ModelFiles/` — (optional) model or resource files used by examples.
- `Speech_To_Text_ESP32/` — separate copy of speech-to-text example and helpers.

## Features

- Voice input (speech-to-text) on ESP32
- Text-to-speech (TTS) playback on ESP32
- Example integrations with cloud-based language models (e.g., ChatGPT/OpenAI)
- Hardware example: animatronic owl sketch

## Prerequisites

- Arduino IDE (or PlatformIO) with ESP32 board support installed
- USB connection to your ESP32 board
- Required libraries referenced by each sketch (install via Library Manager or PlatformIO)
- Wi-Fi network credentials
- If using ChatGPT/OpenAI integration: an API key from OpenAI and appropriate network access

Note: Several sketches reference a `network_param.h` file for Wi-Fi and API configuration — check the folders that include this file and update it with your credentials and keys before building.

## Quick start (Arduino IDE)

1. Open the folder for the example you want to run and open the `.ino` sketch in Arduino IDE.
2. Install any required libraries listed in the top of the sketch comments or in the folder README headers.
3. Edit `network_param.h` (or equivalent config) to set your `WIFI_SSID`, `WIFI_PASSWORD`, and `OPENAI_API_KEY` if needed.
4. Select the correct ESP32 board and serial port under `Tools`.
5. Build and upload to the board.
6. Open the Serial Monitor (115200 baud unless otherwise noted) to view logs and interact.

## Usage notes

- For speech-to-text examples: speak into the device's microphone or feed audio via I2S depending on the sketch.
- For text-to-speech examples: send text via serial or the example's network interface to have the ESP32 synthesize and play audio.
- For ChatGPT integrations: the device typically sends the transcribed text to the cloud API and receives text responses to convert to speech.

## Troubleshooting

- If compilation fails, check that ESP32 board definitions and all required libraries are installed.
- If network/API errors occur, verify Wi-Fi credentials and that your OpenAI API key is valid and not rate-limited.
- Use the Serial Monitor to inspect debug output and error messages.

## Contributing

Contributions, bug reports and improvements are welcome. Please open an issue or submit a pull request with a clear description of changes.

## License

See the `LICENSE` file at the repository root for license details.

## Contact

For questions or help, open an issue in this repository or contact the maintainer.
