{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "printf-call-from-assembly";
  pname = name;
  version = "0.0.1";
  src = ./.;

  buildInputs = with pkgs; [
    gcc
    nasm
  ];

  buildPhase = ''
    nasm -g -f elf64 ./printf.asm -l printf.lst
    ld -g -o printf-thing printf.o -lc --dynamic-linker ${pkgs.glibc}/lib/ld-linux-x86-64.so.2
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./printf-thing $out/bin
  '';
}
