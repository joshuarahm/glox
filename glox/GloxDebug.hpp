#ifndef GLOXDEBUG_HPP_
#define GLOXDEBUG_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxDebug.hpp: <description>
 */

extern FILE* log_file;

#ifdef DEBUG_LEVEL_TRACE
#define DEBUG_LEVEL 6
#endif
#ifdef DEBUG_LEVEL_DEBUG
#define DEBUG_LEVEL 5
#endif
#ifdef DEBUG_LEVEL_INFO
#define DEBUG_LEVEL 4
#endif
#ifdef DEBUG_LEVEL_WARN
#define DEBUG_LEVEL 3
#endif
#ifdef DEBUG_LEVEL_ERROR
#define DEBUG_LEVEL 2
#endif
#ifdef DEBUG_LEVEL_FATAL
#define DEBUG_LEVEL 1
#endif
#ifdef DEBUG_LEVEL_SILENT
#define DEBUG_LEVEL 0
#endif

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 4
#endif

#if DEBUG_LEVEL > 5
#define GloxTrace( category, fmt,  ... ) if(1){ printf("[TRACE] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                             
#define GloxTrace( category, fmt,  ... )
#endif                            
                                  
#if DEBUG_LEVEL > 4          
#define GloxDebug( category, fmt,  ... ) if(1){ printf("[DEBUG] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                             
#define GloxDebug( category, fmt,  ... )
#endif                            
                                  
#if DEBUG_LEVEL > 3          
#define GloxInfo( category, fmt, ... ) if(1){ printf("[INFO] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                            
#define GloxInfo ( category, fmt, ... )
#endif                           
                                 
#if DEBUG_LEVEL > 2         
#define GloxWarn( category, fmt, ... ) if(1){ printf("[WARN] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                            
#define GloxWarn( category, fmt, ... )
#endif                            
                                  
#if DEBUG_LEVEL > 1          
#define GloxError( category, fmt,  ... ) if(1){ printf("[ERROR] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                             
#define GloxError( category, fmt,  ... )
#endif                            
                                  
#if DEBUG_LEVEL > 0          
#define GloxFatal( category, fmt,  ... ) if(1){ printf("[FATAL] (%s) - " fmt, category, ##__VA_ARGS__ ); }
#else                             
#define GloxFatal( category, fmt,  ... )
#endif

#endif /* GLOXDEBUG_HPP_ */
