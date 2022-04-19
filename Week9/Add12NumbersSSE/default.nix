{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "add-12-numbers-using-sse";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  nativeBuildInputs = with pkgs; [
    gcc
    binutils
    nasm
  ];

  dontStrip = true;

  buildPhase = ''
    nasm -g -f elf64 -o add.o add.asm
    gcc -g -m64 -lm -o main main.c add.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv ./main $out/bin
  '';
}
