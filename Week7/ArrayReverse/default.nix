{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "reverse-array-assembly";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  buildInputs = with pkgs; [
    gcc
    binutils
    nasm
  ];

  dontStrip = true;

  buildPhase = ''
    nasm -g -f elf64 -o reverse.o ./reverse.asm
    g++ -g -m64 -o main main.cpp reverse.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
