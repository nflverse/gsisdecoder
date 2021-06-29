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
    const std::string part = hex.substr(i, 2);
    char base16 = std::stoul(part, nullptr, 16);
    ascii += base16;
  }
  return ascii;
}


// [[Rcpp::export]]
CharacterVector decode_ids_cpp(const std::vector< std::string >& new_id){
  size_t n = new_id.size(); 
  CharacterVector out(n);

  for (size_t j = 0; j < n; ++j) {
    const std::string& id = new_id.at(j);
    if (id.size() == 36) {
      const std::string ascii = to_ascii(id.substr(4, 24));
      out.at(j) = ascii;
    }
    else if (id.size() >= 5) {
      out.at(j) = id;
    }
    else {
      out.at(j) = NA_STRING;
    }
  }
  return out;
}

