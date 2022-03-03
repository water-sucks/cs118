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
    g++ -o main main.cpp comp.s
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp ./main $out/bin
  '';
}
