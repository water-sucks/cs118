{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "extern-c-func-call-from-assembly";
  pname = name;
  version = "0.0.1";
  src = ./.;

  buildInputs = with pkgs; [
    gcc
    nasm
  ];

  dontStrip = true;

  buildPhase = ''
    nasm -g -f elf64 ./call-from-assembly.asm
    g++ -c -g call-from-assembly.cpp -o lib.o
    ld -g -o main call-from-assembly.o lib.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
