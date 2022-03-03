{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "call-assembly-function-from-cpp-example";
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
    nasm -g -f elf64 -o average.o ./average.asm
    g++ -g -m64 -o main main.cpp average.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
