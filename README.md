# Plappy Chim

Plappy Chim là một trò chơi 2D thuộc thể loại Endless Runner, được phát triển bằng C++ và thư viện SDL2. Trò chơi lấy cảm hứng từ Flappy Bird, nơi người chơi điều khiển một chú chim vượt qua các chướng ngại vật để ghi điểm cao nhất có thể.

## 🎮 Lối chơi và logic của game

- **Thể loại**: Endless Runner 2D
- **Mục tiêu**: Điều khiển chú chim bay qua các ống cống để ghi điểm cao nhất có thể.
- **Cơ chế điều khiển**:
  - Chim tự động rơi xuống do trọng lực.
  - Người chơi nhấn phím `Space` để chim bay lên một khoảng cố định.
- **Logic game**:
  - Ống cống được tạo ngẫu nhiên với khoảng cách và độ cao khác nhau bằng `rand()`.
  - Phát hiện va chạm giữa chim và ống cống bằng `SDL_HasIntersection()`.
  - Ghi điểm khi chim vượt qua một ống cống.
  - Khi va chạm xảy ra, trò chơi kết thúc và hiển thị màn hình điểm số.

## 🎨 Đồ họa và Âm thanh

- **Đồ họa**:
  - Sử dụng SDL2 để vẽ đồ họa 2D.
  - Sử dụng SDL\_image để load hình ảnh từ file PNG.
  - Hiển thị đối tượng bằng `SDL_RenderCopy()`.
- **Âm thanh**:
  - Sử dụng SDL2\_mixer để phát nhạc và hiệu ứng âm thanh.
  - Load file âm thanh bằng `Mix_LoadWAV()`.
  - Phát âm thanh bằng `Mix_PlayChannel()`.
- **Chữ viết**:
  - Sử dụng SDL2\_ttf để hiển thị chữ trên màn hình.
  - Load font chữ từ file `.ttf`.
  - Tạo texture từ chữ viết bằng `SDL_CreateTextureFromSurface()`.

## 📂 Cấu trúc project

- **Sources**:
  - `bird.cpp`: Xử lý logic và hiển thị chim.
  - `game.cpp`: Quản lý logic tổng thể của game.
  - `graphic.cpp`: Xử lý đồ họa, vẽ các đối tượng lên màn hình.
  - `main.cpp`: Khởi tạo game và chạy vòng lặp chính.
  - `phong_chu.cpp`: Quản lý hiển thị chữ.
  - `pipe.cpp`: Xử lý logic và hiển thị ống cống.
  - `sound.cpp`: Xử lý âm thanh.
- **Headers**:
  - `bird.h`, `game.h`, `graphic.h`, `phong_chu.h`, `pipe.h`, `sound.h`

## 🚀 Các tính năng chính

✔ Điều khiển chim bằng phím `Space`.
✔ Sinh ống cống ngẫu nhiên với khoảng cách và độ cao khác nhau.
✔ Phát hiện va chạm giữa chim và ống cống.
✔ Ghi điểm khi vượt qua ống cống.
✔ Hiển thị điểm số trên màn hình.
✔ Hiệu ứng âm thanh khi chim bay, va chạm và ghi điểm.
✔ Màn hình menu với nút "Chơi game", "Cách chơi", "Thoát".
✔ Màn hình kết thúc game hiển thị điểm số và nút "Chơi lại".
✔ Lưu điểm số cao vào file.
✔ Hướng dẫn chơi trong menu chính.
✔ Sử dụng hình ảnh và âm thanh để tăng trải nghiệm người chơi.
✔ Sử dụng font chữ đẹp để hiển thị thông tin.

## 🔧 Cách cài đặt và chạy game

### Yêu cầu hệ thống

- Hệ điều hành: Windows/Linux/MacOS
- C++ Compiler (g++ hoặc MSVC)
- Thư viện SDL2, SDL2\_image, SDL2\_mixer, SDL2\_ttf

### Cài đặt SDL2 và các thư viện liên quan

```sh
# Windows (với vcpkg)
vcpkg install sdl2 sdl2-image sdl2-mixer sdl2-ttf

# Linux
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```

### Biên dịch và chạy game

```sh
g++ -o PlappyChim main.cpp bird.cpp game.cpp graphic.cpp phong_chu.cpp pipe.cpp sound.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
./PlappyChim
```

## 📜 Giấy phép

Dự án này được phát triển phục vụ mục đích học tập và phi thương mại.

---

🎉 Chúc bạn chơi vui vẻ với Plappy Chim!

