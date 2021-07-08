//绘制球体

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//用来表示输出球体的字符串
const char *shades = ".:!*oe&#%@";
double light[3] = { 30, 30, -50 };
//3维向量标准化
void normalize(double * v)
{
    	//获取3维向量长度
        double len = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    	//标准化
        v[0] /= len; v[1] /= len; v[2] /= len;
}
//计算点积
double dot(double *x, double *y)
{
    	//获取当前向量的模长
        double d = x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
    	//如果点积是负的，转化为正数
        return d < 0 ? -d : 0;
}
//绘制球面
void draw_sphere(double R, double k, double ambient)//(20, 4, .1);
{
    	//两个循环变量i, j 和一个球体表面强度
        int i, j, intensity;
        double b;
        //定义一个三维变量vec 和 横纵坐标
        double vec[3], x, y;
    	//以i为横坐标，进行循环
        for (i = floor(-R); i <= ceil(R); i++) {
            	//x坐标的表示
                x = i + .5;
            	//以j为纵坐标，进行循环，
                for (j = floor(-2 * R); j <= ceil(2 * R); j++) {
                    	//y的坐标表示，因为是以(-2R,2R)区间，所以要除以2
                        y = j / 2. + .5;
                    	//如果在满足下列条件，就给vec向量赋值
                        if (x * x + y * y <= R * R) {
                            	//vec向量横纵坐标为(x,y)
                                vec[0] = x;
                                vec[1] = y;
                            	//保证z坐标在球上
                                vec[2] = sqrt(R * R - x * x - y * y);
                            	//对vec向量进行初始化
                                normalize(vec);
	                            //计算点积的k次方
                                b = pow(dot(light, vec), k) + ambient;
                            	//计算球体表面强度
                                intensity = (1 - b) * (sizeof(shades) - 1);
                            	//如果intensity<0，将其赋为0
                                if (intensity < 0) intensity = 0;
                                //如果intensity超过长度-1 的时候，将其赋值为倒数第二个字符
                                if (intensity >= sizeof(shades) - 1)
                                        intensity = sizeof(shades) - 2;
                                //打印输出的单字符
                                putchar(shades[intensity]);
                        } else
                                putchar(' ');
                }
            	//换行
                putchar('\n');
        }
}
int main()
{
    	//正则化light向量
        normalize(light);
        //分别以不同的 半径和k，画一个球体
        draw_sphere(20, 4, .1);
        draw_sphere(10, 2, .4);
        return 0;
}