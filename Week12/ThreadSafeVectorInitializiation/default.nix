{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "print-array-multithreaded";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  nativeBuildInputs = with pkgs; [
    gcc
    binutils
  ];

  dontStrip = true;

  buildPhase = ''
    g++ -g -m64 -lpthread -o main main.cpp
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv ./main $out/bin
  '';
}
