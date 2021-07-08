//��������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//������ʾ���������ַ���
const char *shades = ".:!*oe&#%@";
double light[3] = { 30, 30, -50 };
//3ά������׼��
void normalize(double * v)
{
    	//��ȡ3ά��������
        double len = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    	//��׼��
        v[0] /= len; v[1] /= len; v[2] /= len;
}
//������
double dot(double *x, double *y)
{
    	//��ȡ��ǰ������ģ��
        double d = x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
    	//�������Ǹ��ģ�ת��Ϊ����
        return d < 0 ? -d : 0;
}
//��������
void draw_sphere(double R, double k, double ambient)//(20, 4, .1);
{
    	//����ѭ������i, j ��һ���������ǿ��
        int i, j, intensity;
        double b;
        //����һ����ά����vec �� ��������
        double vec[3], x, y;
    	//��iΪ�����꣬����ѭ��
        for (i = floor(-R); i <= ceil(R); i++) {
            	//x����ı�ʾ
                x = i + .5;
            	//��jΪ�����꣬����ѭ����
                for (j = floor(-2 * R); j <= ceil(2 * R); j++) {
                    	//y�������ʾ����Ϊ����(-2R,2R)���䣬����Ҫ����2
                        y = j / 2. + .5;
                    	//��������������������͸�vec������ֵ
                        if (x * x + y * y <= R * R) {
                            	//vec������������Ϊ(x,y)
                                vec[0] = x;
                                vec[1] = y;
                            	//��֤z����������
                                vec[2] = sqrt(R * R - x * x - y * y);
                            	//��vec�������г�ʼ��
                                normalize(vec);
	                            //��������k�η�
                                b = pow(dot(light, vec), k) + ambient;
                            	//�����������ǿ��
                                intensity = (1 - b) * (sizeof(shades) - 1);
                            	//���intensity<0�����丳Ϊ0
                                if (intensity < 0) intensity = 0;
                                //���intensity��������-1 ��ʱ�򣬽��丳ֵΪ�����ڶ����ַ�
                                if (intensity >= sizeof(shades) - 1)
                                        intensity = sizeof(shades) - 2;
                                //��ӡ����ĵ��ַ�
                                putchar(shades[intensity]);
                        } else
                                putchar(' ');
                }
            	//����
                putchar('\n');
        }
}
int main()
{
    	//����light����
        normalize(light);
        //�ֱ��Բ�ͬ�� �뾶��k����һ������
        draw_sphere(20, 4, .1);
        draw_sphere(10, 2, .4);
        return 0;
}