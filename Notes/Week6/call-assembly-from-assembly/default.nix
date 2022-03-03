{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "extern-c-func-call-from-assembly";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  buildInputs = with pkgs; [
    gcc
    nasm
  ];

  dontStrip = true;

  buildPhase = ''
    nasm -g -f elf64 ./comp.asm
    nasm -g -f elf64 ./main.asm
    ld -g -o main main.o comp.o
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
