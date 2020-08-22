//����ʽ�̰߳�ȫ 
static Singleton* singleton_hungry_unsaty=new Singleton(); 

//����ʽ�̲߳���ȫ 
//Singleton(Singleton&)=delete;
//Singleton& operator=(const Singleton&)=delete;
static Singleton* singleton_lazy_unsaty=NULL;
static Singleton* instanceSingletonLazyUnsaty(){
	if(singleton_lazy_unsaty==NULL){
		singleton_lazy_unsaty=new Singleton();
	}
	return singleton_lazy_unsaty;
} 

//����ʽ�̰߳�ȫ
static Singleton* singleton_lazy_saty=NULL;
static Singleton* instanceSingletonLazySaty(){
	//pthread_mutex_t mutex;
	//pthread_mutex_init(&mutex,NULL);
	pthread_mutex_lock(&mutex);
	if(singleton_lazy_saty==NULL){
		singleton_lazy_saty=new Singleton();
	}
	pthread_mutex_unlock(&mutex);
	return singleton_lazy_saty;
}
//˫��У�飨�Ƽ���ȫ�� 
static Singleton* singleton_double_check=NULL;
static Singleton* instanceSingletonDoubleCheck(){
	//pthread_mutex_t mutex;
	//pthread_mutex_init(&mutex,NULL);
	if(singleton_double_check==NULL){
		pthread_mutex_lock(&mutex);
		if(singleton_double_check==NULL){
			singleton_double_check=new Singleton();
		}
		pthread_mutex_unlock(&mutex);
	}
	return singleton_double_check;
}

//����У�� 
static Singleton* singleton_one_check=NULL;
static Singleton* instanceSingletonOneCheck(){
	//pthread_mutex_t mutex;
	//pthread_mutex_init(&mutex,NULL);
	if(singleton_one_check==NULL){
		pthread_mutex_lock(&mutex);
		singleton_one_check=new Singleton();
		pthread_mutex_unlock(&mutex);
	}		
	return singleton_one_check;
}

//JAVA:
**************��̬�ڲ���ʵ�� 
public class Singleton {
    private Singleton() {
    }
    private static class SingletonHolder {
        private static final Singleton INSTANCE = new Singleton();
    }
    public static Singleton getUniqueInstance() {
        return SingletonHolder.INSTANCE;
    }
}

//JAVA
*************ö��ʵ��
public enum Singleton {
    INSTANCE;
    private String objName;
    public String getObjName() {
        return objName;
    }
    public void setObjName(String objName) {
        this.objName = objName;
    }
    public static void main(String[] args) {
        // ��������
        Singleton firstSingleton = Singleton.INSTANCE;
        firstSingleton.setObjName("firstName");
        System.out.println(firstSingleton.getObjName());
        Singleton secondSingleton = Singleton.INSTANCE;
        secondSingleton.setObjName("secondName");
        System.out.println(firstSingleton.getObjName());
        System.out.println(secondSingleton.getObjName());
        // �����ȡʵ������
        try {
            Singleton[] enumConstants = Singleton.class.getEnumConstants();
            for (Singleton enumConstant : enumConstants) {
                System.out.println(enumConstant.getObjName());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
} 
