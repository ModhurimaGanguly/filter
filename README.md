# Filter Program

## 📖 Description
This program applies image filters (grayscale, sepia, reflect, blur) to 24‑bit BMP images. It reads an input BMP file, processes its pixels according to the selected filter, and writes the result to a new output BMP file.

## ⚙️ How to Run
make filter
./filter -g input.bmp output.bmp   (grayscale)
./filter -s input.bmp output.bmp   (sepia)
./filter -r input.bmp output.bmp   (reflect)
./filter -b input.bmp output.bmp   (blur)


## 🧪 Example Output
Running the program with different flags produces filtered images:
- gray.bmp → grayscale version
- sepia.bmp → sepia version
- reflect.bmp → horizontally reflected version
- blur.bmp → blurred version

## 🎯 Skills Learned
•  File I/O in C
•  Working with structs and headers (bmp.h)
•  Image processing algorithms (grayscale, sepia, reflect, blur)
•  Memory allocation and management
•  Handling binary data and padding in BMP files
