// ngl need a twinks soft
// thighs to rest my head
// on after making this
// fucking piece of shit

#include <math.h>
#include <immintrin.h>
#include <stdint.h>

#define RH_PI atan(1)*4

typedef struct vec3f_s {
    float x;
    float y;
    float z;
} vec3f_t;

typedef struct vec3i_s {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} vec3i_t;

typedef struct vec2f_s {
    float x;
    float y;
} vec2f_t;

typedef struct vec2i_s {
    uint32_t x;
    uint32_t y;
} vec2i_t;

float rad_to_deg(float rad) {
    return (rad * (180 / RH_PI)); // thanks WikiHow
}

float deg_to_rad(float deg) {
    return (deg / (180 * RH_PI));
}

float rh_sqrt(float x) { // pretty good, ngl
    __m128 src = _mm_set1_ps(x);
    __m128 dest = _mm_sqrt_ps(src);
    float arr[4];
    _mm_storeu_ps(arr, dest);
    return arr[0];
}

float rsqrt(float x) {
    __m128 src = _mm_set1_ps(x);
    __m128 dest = _mm_rsqrt_ps(src);
    float arr[4]; // 128 bit array (32*4 = 128)
    _mm_storeu_ps(arr, dest);
    return arr[0]; // they're all the same 
}

float vec3f_len(vec3f_t vec) {
    return rh_sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float vec3i_len(vec3i_t vec) {
    return rh_sqrt((float)(vec.x * vec.x) + (float)(vec.y * vec.y) + (float)(vec.z * vec.z)); // redneck software engineering
}

float vec2f_len(vec2f_t vec) {
    return rh_sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

int vec2i_len(vec2i_t vec) {
    return rh_sqrt((float)(vec.x * vec.x) + (float)(vec.y * vec.y));
}

void vec3f_norm(vec3f_t vec) {
    float len = vec3f_len(vec); // dont ask me how i did, i just did it, it was hard
    float rlen = rsqrt(len);
    vec.x = vec.x * rlen;
    vec.y = vec.y * rlen;
    vec.z = vec.z * rlen;
}

void vec3i_norm(vec3i_t vec) {
    float len = vec3i_len(vec);
    float rlen = rsqrt(len);
    vec.x = vec.x * rlen;
    vec.y = vec.y * rlen;
    vec.z = vec.z * rlen;
}

void vec2f_norm(vec2f_t vec) {
    float len = vec2f_len(vec);
    float rlen = rsqrt(len);
    vec.x = vec.x * rlen;
    vec.y = vec.y * rlen;
}

void vec2i_norm(vec2i_t vec) {
    float len = vec2i_len(vec);
    float rlen = rsqrt(len);
    vec.x = vec.x * rlen;
    vec.y = vec.y * rlen;
}

int vec3f_comp(vec3f_t vec_a, vec3f_t vec_b) {
    if(vec_a.x != vec_b.x)
        return 0;
    
    if(vec_a.y != vec_b.y)
        return 0;
    
    if(vec_a.z != vec_b.z)
        return 0;

    return 1;
}

int vec3i_comp(vec3i_t vec_a, vec3i_t vec_b) {
    if(vec_a.x != vec_b.x)
        return 0;
    
    if(vec_a.y != vec_b.y)
        return 0;
    
    if(vec_a.z != vec_b.z)
        return 0;

    return 1;
}

int vec2f_comp(vec2f_t vec_a, vec2f_t vec_b) {
    if(vec_a.x != vec_b.x)
        return 0;
    
    if(vec_a.y != vec_b.y)
        return 0;
    
    return 1;
}

int vec2i_comp(vec2i_t vec_a, vec2i_t vec_b) {
    if(vec_a.x != vec_b.x)
        return 0;
    
    if(vec_a.y != vec_b.y)
        return 0;
    
    return 1;
}

float vec3f_dotproduct(vec3f_t vec_a, vec3f_t vec_b) {
    return vec_a.x*vec_b.x + vec_a.y*vec_b.y + vec_a.z*vec_a.z; // product of dot
}

int vec3i_dotproduct(vec3i_t vec_a, vec3i_t vec_b) {
    return vec_a.x*vec_b.x + vec_a.y*vec_b.y + vec_a.z*vec_a.z;
}

float vec2f_dotproduct(vec2f_t vec_a, vec2f_t vec_b) {
    return vec_a.x*vec_b.x + vec_a.y*vec_b.y;
}

int vec2i_dotproduct(vec2i_t vec_a, vec2i_t vec_b) {
    return vec_a.x*vec_b.x + vec_a.y*vec_b.y;
}

vec3f_t vec3f_add(vec3f_t vec_a, vec3f_t vec_b) {
    vec3f_t out;
    out.x = vec_a.x + vec_b.x;
    out.y = vec_a.y + vec_b.y;
    out.z = vec_a.z + vec_b.z;
    return out;
}

vec3i_t vec3i_add(vec3i_t vec_a, vec3i_t vec_b) {
    vec3i_t out;
    out.x = vec_a.x + vec_b.x;
    out.y = vec_a.y + vec_b.y;
    out.z = vec_a.z + vec_b.z;
    return out;
}

vec2f_t vec2f_add(vec3f_t vec_a, vec3f_t vec_b) {
    vec2f_t out;
    out.x = vec_a.x + vec_b.x;
    out.y = vec_a.y + vec_b.y;
    return out;
}

vec2i_t vec2i_add(vec3i_t vec_a, vec3i_t vec_b) {
    vec2i_t out;
    out.x = vec_a.x + vec_b.x;
    out.y = vec_a.y + vec_b.y;
    return out;
}

vec3f_t vec3f_sub(vec3f_t vec_a, vec3f_t vec_b) {
    vec3f_t out;
    out.x = vec_a.x - vec_b.x;
    out.y = vec_a.y - vec_b.y;
    out.z = vec_a.z - vec_b.z;
    return out;
}

vec3i_t vec3i_sub(vec3i_t vec_a, vec3i_t vec_b) {
    vec3i_t out;
    out.x = vec_a.x - vec_b.x;
    out.y = vec_a.y - vec_b.y;
    out.z = vec_a.z - vec_b.z;
    return out;
}

vec2f_t vec2f_sub(vec2f_t vec_a, vec2f_t vec_b) {
    vec2f_t out;
    out.x = vec_a.x - vec_b.x;
    out.y = vec_a.y - vec_b.y;
    return out;
}

vec2i_t vec2i_sub(vec2i_t vec_a, vec2i_t vec_b) {
    vec2i_t out;
    out.x = vec_a.x - vec_b.x;
    out.y = vec_a.y - vec_b.y;
    return out;
}

void vec3f_copy(vec3f_t vec_a, vec3f_t vec_b) {
    vec_b.x = vec_a.x;
    vec_b.y = vec_a.y;
    vec_b.z = vec_a.z;
}

void vec3i_copy(vec3i_t vec_a, vec3i_t vec_b) {
    vec_b.x = vec_a.x;
    vec_b.y = vec_a.y;
    vec_b.z = vec_a.z;
}

void vec2f_copy(vec2f_t vec_a, vec2f_t vec_b) {
    vec_b.x = vec_a.x;
    vec_b.y = vec_a.y;
}

void vec2i_copy(vec2i_t vec_a, vec2i_t vec_b) {
    vec_b.x = vec_a.x;
    vec_b.y = vec_a.y;
}

// did i ever tell you
// what the definiition
// of insanity is?

void vec3f_inv(vec3f_t vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
    vec.z = -vec.z;
}

void vec3i_inv(vec3i_t vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
    vec.z = -vec.z;
}

void vec2f_inv(vec2f_t vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
}

void vec2i_inv(vec2i_t vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
}
