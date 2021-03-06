﻿/* ***************************************************************************
 * textstyle.h -- text style processing module.
 *
 * Copyright (C) 2012-2017 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LCUI project, and may only be used, modified, and
 * distributed under the terms of the GPLv2.
 *
 * (GPLv2 is abbreviation of GNU General Public License Version 2)
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LCUI project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

/* ****************************************************************************
 * textstyle.h -- 文本样式处理模块
 *
 * 版权所有 (C) 2012-2017 归属于 刘超 <lc-soft@live.cn>
 *
 * 这个文件是LCUI项目的一部分，并且只可以根据GPLv2许可协议来使用、更改和发布。
 *
 * (GPLv2 是 GNU通用公共许可证第二版 的英文缩写)
 *
 * 继续使用、修改或发布本文件，表明您已经阅读并完全理解和接受这个许可协议。
 *
 * LCUI 项目是基于使用目的而加以散布的，但不负任何担保责任，甚至没有适销性或特
 * 定用途的隐含担保，详情请参照GPLv2许可协议。
 *
 * 您应已收到附随于本文件的GPLv2许可协议的副本，它通常在LICENSE.TXT文件中，如果
 * 没有，请查看：<http://www.gnu.org/licenses/>.
 * ****************************************************************************/

#ifndef LCUI_TEXTSTYLE_H
#define LCUI_TEXTSTYLE_H

LCUI_BEGIN_HEADER

typedef struct LCUI_TextStyleRec_ {
	LCUI_BOOL has_family:1;
	LCUI_BOOL has_style:1;
	LCUI_BOOL has_weight:1;
	LCUI_BOOL has_back_color:1;
	LCUI_BOOL has_fore_color:1;
	LCUI_BOOL has_pixel_size:1;

	int style;
	int weight;
	int *font_ids;

	LCUI_Color fore_color;
	LCUI_Color back_color;

	int pixel_size;
} LCUI_TextStyleRec, *LCUI_TextStyle;

/** 初始化字体样式数据 */
LCUI_API void TextStyle_Init( LCUI_TextStyle data );

LCUI_API int TextStyle_Copy( LCUI_TextStyle dst, LCUI_TextStyle src );

LCUI_API void TextStyle_Destroy( LCUI_TextStyle data );

/**
 * 设置字体
 * @param[in][out] ts 字体样式数据
 * @param[in] str 字体名称，如果有多个名称则用逗号分隔
 */
LCUI_API int TextStyle_SetFont( LCUI_TextStyle ts, const char *str );

/*-------------------------- StyleTag --------------------------------*/

#define StyleTags_Init LinkedList_Init

/** 从字符串中获取样式标签的名字及样式属性 */
LCUI_API const wchar_t *ScanStyleTag( const wchar_t *wstr, wchar_t *name,
				      int max_name_len, wchar_t *data );

/** 在字符串中获取样式的结束标签，输出的是标签名 */
LCUI_API const wchar_t *ScanStyleEndingTag( const wchar_t *wstr, wchar_t *name );

LCUI_API void StyleTags_Clear( LinkedList *tags );

LCUI_API LCUI_TextStyle StyleTags_GetTextStyle( LinkedList *tags );

/** 处理样式标签 */
LCUI_API const wchar_t* StyleTags_GetStart( LinkedList *tags,
						const wchar_t *str );

/** 处理样式结束标签 */
LCUI_API const wchar_t* StyleTags_GetEnd( LinkedList *tags,
						 const wchar_t *str );

/*------------------------- End StyleTag -----------------------------*/

LCUI_END_HEADER

#endif
