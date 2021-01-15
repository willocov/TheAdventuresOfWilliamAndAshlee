#include "Tileset.h"
Tileset::Tileset() {}
int Tileset::GetFirstGid() {return firstGid;}
string Tileset::GetName() {return name;}
string Tileset::GetTsxSource() { return tsxSource; }
string Tileset::GetImageSource() { return imageSource; }
int Tileset::GetTileWidth() { return tileWidth; }
int Tileset::GetTileHeight() { return tileHeight; }
int Tileset::GetTileCount() { return tileCount; }
int Tileset::GetColumns() { return columns; }

void Tileset::SetFirstGid(int x) {  firstGid = x; }
void Tileset::SetName(string s) {  name =s; }
void Tileset::SetTsxSource(string s) {  tsxSource = s; }
void Tileset::SetImageSource(string s) {  imageSource = s; }
void Tileset::SetTileWidth(int x) {  tileWidth = x; }
void Tileset::SetTileHeight(int x) {  tileHeight  = x; }
void Tileset::SetTileCount(int x) {  tileCount = x; }
void Tileset::SetColumns(int x) {  columns = x; }