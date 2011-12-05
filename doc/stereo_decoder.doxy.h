/**
 * @defgroup StereoDecoder StereoDecoder
 * @ingroup Modules
 *
 * Decode some stereoscopic formats.
 *
 * This module allows you to decode some stereoscopic formats of your different medias and convert it to the current Tao display.
 * For instance, the following code decode a video with a side-by-side format in Tao.
 * @include stereo_decoder.ddd
 *
 * @{
 */

/**
 * Decode horizontal split format.
 * Decode the horizontal split format, also known as side-by-side format.
 */
decode_horizontal_split();

/**
 * Decode vertical split format.
 * Decode the vertical split format, also known as over/under format.
 */
decode_vertical_split();

/**
* @}
*/
