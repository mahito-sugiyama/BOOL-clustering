// copyright: see the header of "main.cc"
void parse(string source, vector<double>& X_raw) {
  char *p;
  string buf;

  p = &source.at(0);
  while (*p != '\0') {
    if (*p == ' ') p++;
    else {
      if (*p == ',' || *p == '\n' || *p == '\r') {
	X_raw.push_back( stof(buf) );
	if (*p == '\n' || *p == '\r') break;
	buf = "";
      }
      else buf += *p; // bind
      p++; // go to the next character
    }
  }
}

int readFile(string input, vector<double>& X_raw, vector<int>& param) {
  int n = 0;
  ifstream ifs(input);
  string buf;
  if(!ifs) return -1; // file open error

  while (getline(ifs, buf)) {
    buf += "\n"; // add linefeed code
    parse(buf, X_raw);
    n++;
  }
  param[0] = n;
  param[1] = floor( (double)X_raw.size() / (double)n );

  return 0;
}

void writeFile(string output, vector<int>& label) {
  ofstream ofs(output);

  for (unsigned int i = 0; i < label.size(); i++) {
    ofs << label[i] << endl;
  }
  ofs << endl;
}
