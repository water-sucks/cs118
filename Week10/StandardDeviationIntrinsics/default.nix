{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation rec {
  name = "standard-deviation-using-intrinsics";
  pname = name;
  version = "0.0.1";
  src = ./.;

  dontConfigure = true;

  nativeBuildInputs = with pkgs; [
    gcc
    binutils
    stb
  ];

  dontStrip = true;

  buildPhase = ''
    gcc -g -m64 -lm -msse4 -o main main.c
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv ./main $out/bin
  '';
}
