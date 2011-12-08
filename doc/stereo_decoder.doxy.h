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
 * Choose decoding mode.
 * Choose the decoding mode among the following ones.
 *     - HSPLIT : horizontal split mode, also known as side-by-side.
 *     - VSPLIT : vertical split mode, also known as top/bottom.
 */
decode_stereo_mode(mode:text);


/**
 * Choose the eye to decode.
 * Choose which eye need to be decoded.
 *     - LEFT  : left eye.
 *     - RIGHT : right eye.
 */
decode_stereo_eye(eye:text);


/**
 * Decode horizontal split format.
 * Decode the horizontal split format, also known as side-by-side format.
 *
 * This function is equivalent to the following code :
 @code
 decode_stereo "HSPLIT", 1.0, 1.0
 @endcode
 */
decode_horizontal_split();

/**
 * Decode vertical split format.
 * Decode the vertical split format, also known as over/under format.
 *
 * This function is equivalent to the following code :
 @code
 decode_stereo "VSPLIT", 1.0, 1.0
 @endcode
 */
decode_vertical_split();

/**
 * Apply a stereoscopic decoding on the current texture.
 * Decode the current texture with the stereoscopic @p mode and
 * redraw it with the size (@p w, @p h).
 *
 * This function is equivalent to the following code :
@code
decode_stereo_mode MODE
left_viewpoint
    decode_stereo_eye "LEFT"
    rectangle 0, 0, w, h
right_viewpoint
    decode_stereo_eye "RIGHT"
    rectangle 0, 0, w, h
@endcode
 */
decode_stereo(mode:text, w:real, h:real);


/**
* @}
*/
