# Base64-Encoder-Decoder-C

A Base64 encoder/decoder CLI tool written in C, built bit by bit through a progressive series of bitwise exercises (`exercises/exercises.md`) — from reading individual bits to the full encoding/decoding algorithm.

## Building

```bash
make
```

## Usage

```bash
./base64 <encode|decode> <input_path> <output_path>
```

```bash
./base64 encode ./photo.png ./photo.b64
./base64 decode ./photo.b64 ./photo.png
```

## Project Structure

```
src/
├── main.c            # CLI argument parsing and file handling
├── base64_encoder.c   # Encoding implementation
├── base64_decoder.c   # Decoding implementation
└── base64.h           # Shared types and declarations

exercises/
└── exercises.md       # Progressive bitwise exercises leading up to the encoder/decoder
```
