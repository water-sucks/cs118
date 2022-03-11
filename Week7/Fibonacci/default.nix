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
    nasm -g -f elf64 -o fibonacci.o ./fibonacci.asm
    g++ -g -m64 -o main main.cpp fibonacci.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
