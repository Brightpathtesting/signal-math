FROM ubuntu:24.04

# System deps
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3 python3-pip \
    cmake ninja-build g++ make \
    git ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Conan
RUN python3 -m pip install conan==2.6.0 --break-system-packages

WORKDIR /work
COPY . /work

# Reproducible build + test
RUN conan profile detect --force && \
    conan install . -s build_type=Release -of build/Release --build=missing && \
    cmake -S . -B build/Release -G Ninja \
      -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake \
      -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build/Release -j && \
    ctest --test-dir build/Release --output-on-failure

# Default command (optional)
CMD ["bash"]
