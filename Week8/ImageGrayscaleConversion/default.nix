{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "convert-image-to-grayscale";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  nativeBuildInputs = with pkgs; [
    gcc
    binutils
    nasm
    stb
  ];

  dontStrip = true;

  buildPhase = ''
    nasm -g -f elf64 -o grayscale.o make-grayscale.asm
    gcc -g -m64 -lm -o convert-grayscale main.c grayscale.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv ./convert-grayscale $out/bin
  '';
}
