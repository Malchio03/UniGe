namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T>EveryN<T>(this IEnumerable<T> source, int n)
    {
        if(source == null)
            throw new ArgumentNullException(nameof(source));
        if(n <= 0)
            throw new ArgumentOutOfRangeException(nameof(n));

        return Iterator();

        IEnumerable<T> Iterator()
        {
            int position = 0;
            foreach(var item in source)
            {
                if(position % n == 0)
                {
                    yield return item;
                } 
                position++;
                           
            }
        }
    }
}
