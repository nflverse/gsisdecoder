################################################################################
# Author: Sebastian Carl
# Purpose: Function to decode NFL GSIS player IDs.
# Code Style Guide: styler::tidyverse_style()
################################################################################

#' Decode NFL GSIS player IDs
#'
#' @param encoded_id A vector of encoded (or decoded) GSIS player IDs in NFL
#' play-by-play data loaded with
#' @description This function is a wrapper around the high efficient c++ function
#' for fast decoding of NFL GSIS player ids intended to be used within the R
#' package nflfastR
#' @return Decoded GSIS player IDs
#' @export
#' @examples
#' \donttest{
#' # Decode IDs including already decoded ids and NA
#' decode_ids(c(
#'   "32013030-2d30-3033-3338-3733fa30c4fa",
#'   "NA",
#'   "00-0033873",
#'   "NA",
#'   "32013030-2d30-3032-3739-3434d4d3846d"
#' ))
#' }
decode_ids <- function(encoded_id) {
  decode_ids_cpp(encoded_id)
}

