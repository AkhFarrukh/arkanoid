FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential cmake ninja-build gdb pkg-config git ca-certificates \
    liballegro5-dev liballegro-ttf5-dev \
    libgl1-mesa-dri mesa-utils x11-apps \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace