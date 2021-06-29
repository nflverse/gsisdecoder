#include <Rcpp.h>
using namespace Rcpp;

std::string to_ascii(const std::string& cut) {
  // convert to hex-string
  std::string hex;

  for (size_t k = 0; k < cut.size(); ++k) {
    if (cut.substr(k, 1) != "-") {
      hex += cut.substr(k, 1);
    }
  }

  // get the ASCII representation
  std::string ascii;
  for (size_t i = 0; i < hex.size(); i += 2) {
    char base16 = std::stoul(hex.substr(i, 2), nullptr, 16);
    ascii += base16;
  }
  return ascii;
}


// [[Rcpp::export]]
CharacterVector decode_ids_cpp(const std::vector<std::string>& new_id){
  size_t n = new_id.size(); 
  CharacterVector out(n);

  for (size_t j = 0; j < n; ++j) {
    const std::string& id = new_id[j];
    const size_t sz = id.size();
    if (sz == 36) {
      out[j] = to_ascii(id.substr(4, 24));
    }
    else if (sz >= 5) {
      out[j] = id;
    }
    else {
      out[j] = NA_STRING;
    }
  }
  return out;
}

