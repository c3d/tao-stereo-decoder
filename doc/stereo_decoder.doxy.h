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
decode_stereo "HSPLIT", texture_width / 2, texture_height
 @endcode
 */
decode_horizontal_split();

/**
 * Decode vertical split format.
 * Decode the vertical split format, also known as over/under format.
 *
 * This function is equivalent to the following code :
 @code
 decode_stereo "VSPLIT", texture_width, texture_height / 2
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
decode_stereo(mode:text, w:integer, h:integer);

/**
 * Draw only for the specified stereoscopic point of views.
 *
 * @p viewpoints is a bitmask that specifies for which eyes the
 * drawing should take place.
 *
 * Viewpoints are numbered from left to right. When there are no more
 * that two viewpoints, 1 is the left eye and 2 the right eye so that:
 *
 * - left_viewpoint is synonym for stereo_viewpoints 1.
 * - right_viewpoint is synonym for stereo_viewpoints 2.
 *
 * The following example shows a square to the left eye and a circle
 * to the right eye (such code may be used to check if a stereoscopic
 * setup works properly):
@code
clear_color 0, 0, 0, 0
color "white"
left_viewpoint
    rectangle 0, 0, 100, 100
right_viewpoint
    circle 0, 0, 50
text_box 0, 0, window_width, window_height,
    align_center
    vertical_align_bottom
    font "Andika Basic", 40
    color "white"
    text "Left eye: square     Right eye: circle"
@endcode
 * @note This primitive only affects the drawing phase, not the execution
 * phase. In other words, the code guarded by stereo_viewpoints is
 * always executed, whatever the value @p viewpoints may be. In that
 * respect, the stereo_viewpoint primitive behaves pretty much like
 * @ref locally. It is only during the drawing phase that conditional
 * drawing occurs.
 */
stereo_viewpoints(viewpoints:integer);

/**
 * Draw only for the left eye.
 * Equivalent to: stereo_viewpoints 1
 */
left_viewpoint(B:block);

/**
 * Draw only for the right eye.
 * Equivalent to: stereo_viewpoints 2
 */
right_viewpoint(B:block);

/**
* @}
*/
