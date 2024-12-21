#pragma once

#include "fwd.h"

// #define FONT_AWESOME_6_ICONS
// #define LUCIDE_ICONS
#define MATERIAL_SYMBOLS_ICONS
// #define MATERIAL_DESIGN_ICONS
// #define MATERIAL_DESIGN_ICONS_ICONS

#if defined(FONT_AWESOME_6_ICONS)
#include "hello_imgui/icons_font_awesome_6.h"
#define FONT_ICON_FILE_NAME_MY "fonts/Font_Awesome_6_Free-Solid-900.otf"
#define ICON_MIN_MY            ICON_MIN_FA
#define ICON_MAX_16_MY         ICON_MAX_16_FA
#define ICON_MAX_MY            ICON_MAX_FA

#define ICON_MY_OPEN_IMAGE         ICON_FA_FOLDER_OPEN
#define ICON_MY_ABOUT              ICON_FA_CIRCLE_INFO
#define ICON_MY_FIT_AXES           ICON_FA_ARROWS_LEFT_RIGHT_TO_LINE
#define ICON_MY_MANUAL_AXES        ICON_FA_UP_DOWN_LEFT_RIGHT
#define ICON_MY_LIST_OL            ICON_FA_LIST_OL
#define ICON_MY_VISIBILITY         ICON_FA_EYE
#define ICON_MY_KEY_CONTROL        ICON_FA_ANGLE_UP
#define ICON_MY_KEY_COMMAND        "Cmd"
#define ICON_MY_KEY_OPTION         "Alt"
#define ICON_MY_KEY_SHIFT          "Shift"
#define ICON_MY_CHANNEL_GROUP      ICON_FA_LAYER_GROUP
#define ICON_MY_QUIT               ICON_FA_POWER_OFF
#define ICON_MY_COMMAND_PALETTE    ICON_FA_BARS
#define ICON_MY_TWEAK_THEME        ICON_FA_PAINTBRUSH
#define ICON_MY_SHOW_ALL_WINDOWS   ICON_FA_WINDOW_MAXIMIZE
#define ICON_MY_HIDE_ALL_WINDOWS   ICON_FA_WINDOW_MINIMIZE
#define ICON_MY_RESTORE_LAYOUT     ICON_FA_WINDOW_RESTORE
#define ICON_MY_EXPOSURE           "EV:"
#define ICON_MY_REDUCE_EXPOSURE    ICON_FA_MOON
#define ICON_MY_INCREASE_EXPOSURE  ICON_FA_SUN
#define ICON_MY_RESET_TONEMAPPING  ICON_FA_ARROWS_ROTATE
#define ICON_MY_NORMALIZE_EXPOSURE ICON_FA_WAND_MAGIC_SPARKLES
#define ICON_MY_DITHER             ICON_FA_CHESS_BOARD
#define ICON_MY_CLAMP_TO_LDR       ICON_FA_ARROWS_UP_TO_LINE
#define ICON_MY_SHOW_GRID          ICON_FA_BORDER_ALL
#define ICON_MY_SAVE_AS            ICON_FA_FLOPPY_DISK
#define ICON_MY_CLOSE              ICON_FA_CIRCLE_XMARK
#define ICON_MY_CLOSE_ALL          ICON_FA_CIRCLE_XMARK
#define ICON_MY_ZOOM_OUT           ICON_FA_MAGNIFYING_GLASS_MINUS
#define ICON_MY_ZOOM_IN            ICON_FA_MAGNIFYING_GLASS_PLUS
#define ICON_MY_ZOOM_100           ICON_FA_MAGNIFYING_GLASS
#define ICON_MY_FIT_TO_WINDOW      ICON_FA_MAXIMIZE
#define ICON_MY_CENTER             ICON_FA_ARROWS_TO_DOT
#define ICON_MY_FILTER             ICON_FA_FILTER
#define ICON_MY_DELETE             ICON_FA_DELETE_LEFT
#define ICON_MY_IMAGE              ICON_FA_IMAGE
#define ICON_MY_IMAGES             ICON_FA_IMAGES
#define ICON_MY_REFERENCE_IMAGE    ICON_FA_EYE_LOW_VISION
#define ICON_MY_THEME              ICON_FA_PAINTBRUSH
#define ICON_MY_ARROW_UP           ICON_FA_ARROW_UP
#define ICON_MY_ARROW_DOWN         ICON_FA_ARROW_DOWN
#define ICON_MY_KEY_RETURN         "return"
#define ICON_MY_KEY_ESC            "esc"
#define ICON_MY_LOG_LEVEL          ICON_FA_BULLHORN
#define ICON_MY_LOG_LEVEL_TRACE    ICON_FA_VOLUME_HIGH
#define ICON_MY_LOG_LEVEL_DEBUG    ICON_FA_BUG_SLASH
#define ICON_MY_LOG_LEVEL_INFO     ICON_FA_CIRCLE_INFO
#define ICON_MY_LOG_LEVEL_WARN     ICON_FA_TRIANGLE_EXCLAMATION
#define ICON_MY_LOG_LEVEL_ERROR    ICON_FA_CIRCLE_XMARK
#define ICON_MY_LOG_LEVEL_CRITICAL ICON_FA_BOMB
#define ICON_MY_LOG_LEVEL_OFF      ICON_FA_VOLUME_XMARK
#define ICON_MY_GREATER_EQUAL      ICON_FA_GREATER_THAN_EQUAL
#define ICON_MY_TRASH_CAN          ICON_FA_TRASH_CAN
#define ICON_MY_LOCK               ICON_FA_LOCK
#define ICON_MY_LOCK_OPEN          ICON_FA_LOCK_OPEN
#define ICON_MY_TEXT_WRAP_ON       ICON_FA_BARS_STAGGERED
#define ICON_MY_TEXT_WRAP_OFF      ICON_FA_ALIGN_LEFT
#define ICON_MY_WIDEST             ICON_FA_VOLUME_HIGH
#define ICON_MY_LINK               ICON_FA_LINK

#elif defined(LUCIDE_ICONS)
#include "IconsLucide.h"
#define FONT_ICON_FILE_NAME_MY "fonts/lucide.ttf"
#define ICON_MIN_MY            ICON_MIN_LC
#define ICON_MAX_16_MY         ICON_MAX_16_LC
#define ICON_MAX_MY            ICON_MAX_LC

#define ICON_MY_OPEN_IMAGE         ICON_LC_FOLDER_OPEN
#define ICON_MY_ABOUT              ICON_LC_INFO
#define ICON_MY_FIT_AXES           ICON_LC_LOCK
#define ICON_MY_MANUAL_AXES        ICON_LC_MOVE
#define ICON_MY_LIST_OL            ICON_LC_LIST_ORDERED
#define ICON_MY_VISIBILITY         ICON_LC_EYE
#define ICON_MY_KEY_CONTROL        ICON_LC_CHEVRON_UP
#define ICON_MY_KEY_COMMAND        "Cmd"
#define ICON_MY_KEY_SHIFT          ICON_LC_ARROW_BIG_UP
#define ICON_MY_CHANNEL_GROUP      ICON_LC_LAYERS
#define ICON_MY_QUIT               ICON_LC_POWER
#define ICON_MY_COMMAND_PALETTE    ICON_LC_MENU
#define ICON_MY_TWEAK_THEME        ICON_LC_PENCIL_RULER
#define ICON_MY_SHOW_ALL_WINDOWS   ICON_LC_LAYOUT_TEMPLATE
#define ICON_MY_HIDE_ALL_WINDOWS   ICON_LC_SQUARE
#define ICON_MY_RESTORE_LAYOUT     ICON_LC_PANELS_TOP_LEFT
#define ICON_MY_EXPOSURE           "EV:"
#define ICON_MY_REDUCE_EXPOSURE    ICON_LC_SUN_DIM
#define ICON_MY_INCREASE_EXPOSURE  ICON_LC_SUN
#define ICON_MY_RESET_TONEMAPPING  ICON_LC_ROTATE_CCW
#define ICON_MY_NORMALIZE_EXPOSURE ICON_LC_WAND_SPARKLES
#define ICON_MY_DITHER             ICON_LC_DIFF
#define ICON_MY_CLAMP_TO_LDR       ICON_LC_ARROW_DOWN_FROM_LINE
#define ICON_MY_SHOW_GRID          ICON_LC_GRID_3X3
#define ICON_MY_SAVE_AS            ICON_LC_SAVE
#define ICON_MY_CLOSE              ICON_LC_CIRCLE_X
#define ICON_MY_CLOSE_ALL          ICON_LC_CIRCLE_X
#define ICON_MY_ZOOM_OUT           ICON_LC_ZOOM_OUT
#define ICON_MY_ZOOM_IN            ICON_LC_ZOOM_IN
#define ICON_MY_ZOOM_100           ""
#define ICON_MY_FIT_TO_WINDOW      ICON_LC_FULLSCREEN
#define ICON_MY_CENTER             ""
#define ICON_MY_FILTER             ICON_LC_FILTER
#define ICON_MY_DELETE             ICON_LC_DELETE
#define ICON_MY_IMAGE              ICON_LC_IMAGE
#define ICON_MY_IMAGES             ICON_LC_IMAGES
#define ICON_MY_REFERENCE_IMAGE    ICON_LC_VIEW
#define ICON_MY_THEME              ICON_LC_PALETTE
#define ICON_MY_ARROW_UP           ICON_LC_ARROW_UP
#define ICON_MY_ARROW_DOWN         ICON_LC_ARROW_DOWN
#define ICON_MY_KEY_RETURN         ICON_LC_CORNER_DOWN_LEFT
#define ICON_MY_KEY_ESC            ICON_LC_CIRCLE_ARROW_OUT_UP_LEFT
#define ICON_MY_LOG_LEVEL          ICON_LC_MEGAPHONE
#define ICON_MY_LOG_LEVEL_TRACE    ICON_LC_VOLUME_2
#define ICON_MY_LOG_LEVEL_DEBUG    ICON_LC_BUG_OFF
#define ICON_MY_LOG_LEVEL_INFO     ICON_LC_INFO
#define ICON_MY_LOG_LEVEL_WARN     ICON_LC_TRIANGLE_ALERT
#define ICON_MY_LOG_LEVEL_ERROR    ICON_LC_CIRCLE_X
#define ICON_MY_LOG_LEVEL_CRITICAL ICON_LC_BOMB
#define ICON_MY_LOG_LEVEL_OFF      ICON_LC_VOLUME_X
#define ICON_MY_GREATER_EQUAL      ">="
#define ICON_MY_TRASH_CAN          ICON_LC_TRASH_2
#define ICON_MY_LOCK               ICON_LC_LOCK
#define ICON_MY_LOCK_OPEN          ICON_LC_LOCK_OPEN
#define ICON_MY_TEXT_WRAP_ON       ICON_LC_WRAP_TEXT
#define ICON_MY_TEXT_WRAP_OFF      ICON_LC_ALIGN_LEFT
#define ICON_MY_WIDEST             ICON_LC_VOLUME_X
#define ICON_MY_LINK               ICON_LC_LINK

#elif defined(MATERIAL_SYMBOLS_ICONS)
#include "IconsMaterialSymbols.h"
#define FONT_ICON_FILE_NAME_MY "fonts/MaterialSymbolsRounded_Filled-Regular.ttf"
#define ICON_MIN_MY            ICON_MIN_MS
#define ICON_MAX_16_MY         ICON_MAX_16_MS
#define ICON_MAX_MY            ICON_MAX_MS

#define ICON_MY_OPEN_IMAGE         ICON_MS_FOLDER_OPEN
#define ICON_MY_ABOUT              ICON_MS_INFO
#define ICON_MY_FIT_AXES           ICON_MS_LOCK
#define ICON_MY_MANUAL_AXES        ICON_MS_DRAG_PAN
#define ICON_MY_LIST_OL            ICON_MS_FORMAT_LIST_NUMBERED
#define ICON_MY_VISIBILITY         ICON_MS_VISIBILITY
#define ICON_MY_KEY_CONTROL        ICON_MS_KEYBOARD_CONTROL_KEY
#define ICON_MY_KEY_COMMAND        ICON_MS_KEYBOARD_COMMAND_KEY
#define ICON_MY_KEY_OPTION         ICON_MS_KEYBOARD_OPTION_KEY
#define ICON_MY_KEY_SHIFT          ICON_MS_SHIFT
#define ICON_MY_CHANNEL_GROUP      ICON_MS_LAYERS
#define ICON_MY_QUIT               ICON_MS_POWER_SETTINGS_NEW
#define ICON_MY_COMMAND_PALETTE    ICON_MS_MENU_OPEN
#define ICON_MY_TWEAK_THEME        ICON_MS_TUNE
#define ICON_MY_SHOW_ALL_WINDOWS   ICON_MS_SPACE_DASHBOARD
#define ICON_MY_HIDE_ALL_WINDOWS   ICON_MS_CALENDAR_VIEW_DAY
#define ICON_MY_RESTORE_LAYOUT     ICON_MS_DASHBOARD
#define ICON_MY_EXPOSURE           ICON_MS_EXPOSURE
#define ICON_MY_REDUCE_EXPOSURE    ICON_MS_EXPOSURE_NEG_1
#define ICON_MY_INCREASE_EXPOSURE  ICON_MS_EXPOSURE_PLUS_1
#define ICON_MY_RESET_TONEMAPPING  ICON_MS_RESET_BRIGHTNESS
#define ICON_MY_NORMALIZE_EXPOSURE ICON_MS_VERTICAL_ALIGN_TOP
// #define ICON_MY_NORMALIZE_EXPOSURE ICON_MS_BRIGHTNESS_AUTO
#define ICON_MY_DITHER             ICON_MS_BLUR_ON
// #define ICON_MY_CLAMP_TO_LDR       ICON_MS_COMPRESS
#define ICON_MY_CLAMP_TO_LDR       ICON_MS_TEXT_SELECT_MOVE_DOWN
#define ICON_MY_SHOW_GRID          ICON_MS_GRID_4X4
#define ICON_MY_SAVE_AS            ICON_MS_SAVE
#define ICON_MY_CLOSE              ICON_MS_DISABLED_BY_DEFAULT
#define ICON_MY_CLOSE_ALL          ICON_MS_TAB_CLOSE
#define ICON_MY_ZOOM_OUT           ICON_MS_ZOOM_OUT
#define ICON_MY_ZOOM_IN            ICON_MS_ZOOM_IN
#define ICON_MY_ZOOM_100           ICON_MS_VIEW_REAL_SIZE
#define ICON_MY_FIT_TO_WINDOW      ICON_MS_FIT_SCREEN
#define ICON_MY_CENTER             ICON_MS_RECENTER
#define ICON_MY_FILTER             ICON_MS_FILTER_ALT
#define ICON_MY_DELETE             ICON_MS_BACKSPACE
#define ICON_MY_IMAGE              ICON_MS_IMAGE
#define ICON_MY_IMAGES             ICON_MS_PHOTO_LIBRARY
#define ICON_MY_REFERENCE_IMAGE    ICON_MS_COMPARE
#define ICON_MY_THEME              ICON_MS_BRUSH
#define ICON_MY_ARROW_UP           ICON_MS_ARROW_UPWARD
#define ICON_MY_ARROW_DOWN         ICON_MS_ARROW_DOWNWARD
#define ICON_MY_KEY_RETURN         ICON_MS_KEYBOARD_RETURN
#define ICON_MY_KEY_ESC            "esc"
#define ICON_MY_LOG_LEVEL          ICON_MS_CAMPAIGN
#define ICON_MY_LOG_LEVEL_TRACE    ICON_MS_VOLUME_UP
#define ICON_MY_LOG_LEVEL_DEBUG    ICON_MS_BUG_REPORT
#define ICON_MY_LOG_LEVEL_INFO     ICON_MS_INFO
#define ICON_MY_LOG_LEVEL_WARN     ICON_MS_WARNING
#define ICON_MY_LOG_LEVEL_ERROR    ICON_MS_REPORT
#define ICON_MY_LOG_LEVEL_CRITICAL ICON_MS_BOMB
#define ICON_MY_LOG_LEVEL_OFF      ICON_MS_VOLUME_OFF
#define ICON_MY_GREATER_EQUAL      ">="
#define ICON_MY_TRASH_CAN          ICON_MS_DELETE
#define ICON_MY_LOCK               ICON_MS_LOCK
#define ICON_MY_LOCK_OPEN          ICON_MS_LOCK_OPEN
#define ICON_MY_TEXT_WRAP_ON       ICON_MS_WRAP_TEXT
#define ICON_MY_TEXT_WRAP_OFF      ICON_MS_FORMAT_ALIGN_LEFT
#define ICON_MY_WIDEST             ICON_MS_VOLUME_UP
#define ICON_MY_LINK               ICON_MS_LINK
#define ICON_MY_TOOLBAR            ICON_MS_TOOLBAR
#define ICON_MY_STATUSBAR          ICON_MS_BOTTOM_PANEL_OPEN
#define ICON_MY_HIDE_GUI           ICON_MS_CHECK_BOX_OUTLINE_BLANK
#define ICON_MY_FPS                ICON_MS_SPEED

#elif defined(MATERIAL_DESIGN_ICONS)

#include "IconsMaterialDesign.h"
#define FONT_ICON_FILE_NAME_MY "fonts/MaterialIcons-Regular.ttf"
#define ICON_MIN_MY            ICON_MIN_MD
#define ICON_MAX_16_MY         ICON_MAX_16_MD
#define ICON_MAX_MY            ICON_MAX_MD

#define ICON_MY_OPEN_IMAGE         ICON_MD_FOLDER_OPEN
#define ICON_MY_ABOUT              ICON_MD_INFO
#define ICON_MY_FIT_AXES           ICON_MD_ZOOM_IN_MAP
#define ICON_MY_MANUAL_AXES        ICON_MD_OPEN_WITH
#define ICON_MY_LIST_OL            ICON_MD_FORMAT_LIST_NUMBERED
#define ICON_MY_VISIBILITY         ICON_MD_VISIBILITY
#define ICON_MY_KEY_CONTROL        ICON_MD_KEYBOARD_CONTROL_KEY
#define ICON_MY_KEY_COMMAND        ICON_MD_KEYBOARD_COMMAND_KEY
#define ICON_MY_KEY_OPTION         ICON_MD_KEYBOARD_OPTION_KEY
#define ICON_MY_KEY_SHIFT          "Shift"
#define ICON_MY_CHANNEL_GROUP      ICON_MD_LAYERS
#define ICON_MY_QUIT               ICON_MD_POWER_SETTINGS_NEW
#define ICON_MY_COMMAND_PALETTE    ICON_MD_MENU_OPEN
#define ICON_MY_TWEAK_THEME        ICON_MD_TUNE
#define ICON_MY_SHOW_ALL_WINDOWS   ICON_MD_SPACE_DASHBOARD
#define ICON_MY_HIDE_ALL_WINDOWS   ICON_MD_CROP_SQUARE
#define ICON_MY_RESTORE_LAYOUT     ICON_MD_DASHBOARD
#define ICON_MY_EXPOSURE           ICON_MD_EXPOSURE
#define ICON_MY_REDUCE_EXPOSURE    ICON_MD_EXPOSURE_NEG_1
#define ICON_MY_INCREASE_EXPOSURE  ICON_MD_EXPOSURE_PLUS_1
#define ICON_MY_RESET_TONEMAPPING  ICON_MD_FORMAT_COLOR_RESET
#define ICON_MY_NORMALIZE_EXPOSURE ICON_MD_EXPAND
#define ICON_MY_DITHER             ICON_MD_BLUR_ON
#define ICON_MY_CLAMP_TO_LDR       ICON_MD_COMPRESS
#define ICON_MY_SHOW_GRID          ICON_MD_BORDER_ALL
#define ICON_MY_SAVE_AS            ICON_MD_SAVE
#define ICON_MY_CLOSE              ICON_MD_CANCEL
#define ICON_MY_CLOSE_ALL          ICON_MD_CANCEL
#define ICON_MY_ZOOM_OUT           ICON_MD_ZOOM_OUT
#define ICON_MY_ZOOM_IN            ICON_MD_ZOOM_IN
#define ICON_MY_ZOOM_100           ICON_MD_1X_MOBILEDATA
#define ICON_MY_FIT_TO_WINDOW      ICON_MD_FIT_SCREEN
#define ICON_MY_CENTER             ICON_MD_FILTER_CENTER_FOCUS
#define ICON_MY_FILTER             ICON_MD_FILTER_ALT
#define ICON_MY_DELETE             ICON_MD_BACKSPACE
#define ICON_MY_IMAGE              ICON_MD_IMAGE
#define ICON_MY_IMAGES             ICON_MD_IMAGE
#define ICON_MY_REFERENCE_IMAGE    ICON_MD_COMPARE
#define ICON_MY_THEME              ICON_MD_BRUSH
#define ICON_MY_ARROW_UP           ICON_MD_ARROW_UPWARD
#define ICON_MY_ARROW_DOWN         ICON_MD_ARROW_DOWNWARD
#define ICON_MY_KEY_RETURN         ICON_MD_KEYBOARD_RETURN
#define ICON_MY_KEY_ESC            "esc"
#define ICON_MY_LOG_LEVEL          ICON_MD_CAMPAIGN
#define ICON_MY_LOG_LEVEL_TRACE    ICON_MD_VOLUME_UP
#define ICON_MY_LOG_LEVEL_DEBUG    ICON_MD_BUG_REPORT
#define ICON_MY_LOG_LEVEL_INFO     ICON_MD_INFO
#define ICON_MY_LOG_LEVEL_WARN     ICON_MD_WARNING
#define ICON_MY_LOG_LEVEL_ERROR    ICON_MD_ERROR
#define ICON_MY_LOG_LEVEL_CRITICAL ICON_MD_DANGEROUS
#define ICON_MY_LOG_LEVEL_OFF      ICON_MD_VOLUME_OFF
#define ICON_MY_GREATER_EQUAL      ">="
#define ICON_MY_TRASH_CAN          ICON_MD_DELETE
#define ICON_MY_LOCK               ICON_MD_LOCK
#define ICON_MY_LOCK_OPEN          ICON_MD_LOCK_OPEN
#define ICON_MY_TEXT_WRAP_ON       ICON_MD_WRAP_TEXT
#define ICON_MY_TEXT_WRAP_OFF      ICON_MD_FORMAT_ALIGN_LEFT
#define ICON_MY_WIDEST             ICON_MD_VOLUME_UP
#define ICON_MY_LINK               ICON_MD_LINK

#elif defined(MATERIAL_DESIGN_ICONS_ICONS)

#include "IconsMaterialDesignIcons.h"
#define FONT_ICON_FILE_NAME_MY "fonts/materialdesignicons-webfont.ttf"
#define ICON_MIN_MY            ICON_MIN_MDI
#define ICON_MAX_16_MY         ICON_MAX_16_MDI
#define ICON_MAX_MY            ICON_MAX_MDI

#define ICON_MY_OPEN_IMAGE         ICON_MDI_FOLDER_OPEN
#define ICON_MY_ABOUT              ICON_MDI_INFORMATION
#define ICON_MY_FIT_AXES           ICON_MDI_FIT_TO_PAGE_OUTLINE
#define ICON_MY_MANUAL_AXES        ICON_MDI_PAN
#define ICON_MY_LIST_OL            ICON_MDI_FORMAT_LIST_NUMBERED
#define ICON_MY_VISIBILITY         ICON_MDI_EYE
#define ICON_MY_KEY_CONTROL        ICON_MDI_APPLE_KEYBOARD_CONTROL
#define ICON_MY_KEY_COMMAND        ICON_MDI_APPLE_KEYBOARD_COMMAND
#define ICON_MY_KEY_OPTION         ICON_MDI_APPLE_KEYBOARD_OPTION
#define ICON_MY_KEY_SHIFT          ICON_MDI_APPLE_KEYBOARD_SHIFT
#define ICON_MY_CHANNEL_GROUP      ICON_MDI_LAYERS
#define ICON_MY_QUIT               ICON_MDI_POWER_CYCLE
#define ICON_MY_COMMAND_PALETTE    ICON_MDI_MENU_OPEN
#define ICON_MY_TWEAK_THEME        ICON_MDI_TUNE
#define ICON_MY_SHOW_ALL_WINDOWS   ICON_MDI_VIEW_COMPACT
#define ICON_MY_HIDE_ALL_WINDOWS   ICON_MDI_WINDOW_MAXIMIZE
#define ICON_MY_RESTORE_LAYOUT     ICON_MDI_VIEW_QUILT
#define ICON_MY_EXPOSURE           ICON_MDI_PLUS_MINUS_VARIANT
#define ICON_MY_REDUCE_EXPOSURE    ICON_MDI_BRIGHTNESS_2
#define ICON_MY_INCREASE_EXPOSURE  ICON_MDI_BRIGHTNESS_7
#define ICON_MY_RESET_TONEMAPPING  ICON_MDI_RESTART
#define ICON_MY_NORMALIZE_EXPOSURE ICON_MDI_ARROW_COLLAPSE_UP
#define ICON_MY_DITHER             ICON_MDI_CHECKERBOARD
#define ICON_MY_CLAMP_TO_LDR       ICON_MDI_ARROW_EXPAND_DOWN
#define ICON_MY_SHOW_GRID          ICON_MDI_BORDER_ALL
#define ICON_MY_SAVE_AS            ICON_MDI_CONTENT_SAVE
#define ICON_MY_CLOSE              ICON_MDI_CLOSE_BOX
#define ICON_MY_CLOSE_ALL          ICON_MDI_CLOSE_BOX_MULTIPLE
#define ICON_MY_ZOOM_OUT           ICON_MDI_MAGNIFY_MINUS
#define ICON_MY_ZOOM_IN            ICON_MDI_MAGNIFY_PLUS
#define ICON_MY_ZOOM_100           ICON_MDI_PERCENT
#define ICON_MY_FIT_TO_WINDOW      ICON_MDI_FIT_TO_PAGE
#define ICON_MY_CENTER             ICON_MDI_IMAGE_FILTER_CENTER_FOCUS
#define ICON_MY_FILTER             ICON_MDI_FILTER
#define ICON_MY_DELETE             ICON_MDI_BACKSPACE
#define ICON_MY_IMAGE              ICON_MDI_IMAGE
#define ICON_MY_IMAGES             ICON_MDI_IMAGE_MULTIPLE
#define ICON_MY_REFERENCE_IMAGE    ICON_MDI_COMPARE
#define ICON_MY_THEME              ICON_MDI_BRUSH
#define ICON_MY_ARROW_UP           ICON_MDI_ARROW_UP
#define ICON_MY_ARROW_DOWN         ICON_MDI_ARROW_DOWN
#define ICON_MY_KEY_RETURN         ICON_MDI_KEYBOARD_RETURN
#define ICON_MY_KEY_ESC            ICON_MDI_KEYBOARD_ESC
#define ICON_MY_LOG_LEVEL          ICON_MDI_BULLHORN
#define ICON_MY_LOG_LEVEL_TRACE    ICON_MDI_VOLUME_HIGH
#define ICON_MY_LOG_LEVEL_DEBUG    ICON_MDI_BUG
#define ICON_MY_LOG_LEVEL_INFO     ICON_MDI_INFORMATION
#define ICON_MY_LOG_LEVEL_WARN     ICON_MDI_ALERT
#define ICON_MY_LOG_LEVEL_ERROR    ICON_MDI_ALERT_OCTAGON
#define ICON_MY_LOG_LEVEL_CRITICAL ICON_MDI_BOMB
#define ICON_MY_LOG_LEVEL_OFF      ICON_MDI_VOLUME_OFF
#define ICON_MY_GREATER_EQUAL      ICON_MDI_GREATER_THAN_OR_EQUAL
#define ICON_MY_TRASH_CAN          ICON_MDI_DELETE
#define ICON_MY_LOCK               ICON_MDI_LOCK
#define ICON_MY_LOCK_OPEN          ICON_MDI_LOCK_OPEN
#define ICON_MY_TEXT_WRAP_ON       ICON_MDI_FORMAT_TEXT_WRAPPING_WRAP
#define ICON_MY_TEXT_WRAP_OFF      ICON_MDI_FORMAT_TEXT_WRAPPING_OVERFLOW
#define ICON_MY_NUMBERIC_1         ICON_MDI_NUMERIC_1_BOX
#define ICON_MY_NUMBERIC_2         ICON_MDI_NUMERIC_2_BOX
#define ICON_MY_NUMBERIC_3         ICON_MDI_NUMERIC_3_BOX
#define ICON_MY_NUMBERIC_4         ICON_MDI_NUMERIC_4_BOX
#define ICON_MY_NUMBERIC_5         ICON_MDI_NUMERIC_5_BOX
#define ICON_MY_NUMBERIC_6         ICON_MDI_NUMERIC_6_BOX
#define ICON_MY_NUMBERIC_7         ICON_MDI_NUMERIC_7_BOX
#define ICON_MY_NUMBERIC_8         ICON_MDI_NUMERIC_8_BOX
#define ICON_MY_NUMBERIC_9         ICON_MDI_NUMERIC_9_BOX
#define ICON_MY_NUMBERIC_10        ICON_MDI_NUMERIC_10_BOX
#define ICON_MY_WIDEST             ICON_MDI_VOLUME_HIGH
#define ICON_MY_LINK               ICON_MDI_LINK

#endif