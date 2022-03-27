{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = with pkgs; [ imv ];
  nativeBuildInputs = with pkgs; [ stb ];
}
