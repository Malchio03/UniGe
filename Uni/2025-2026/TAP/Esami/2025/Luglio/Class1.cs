namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T>TakeThenSkip<T>(this IEnumerable<T> source, int take, int skip)
    {
        if(source == null)
            throw new ArgumentNullException(nameof(source));
        if(take <= 0)
            throw new ArgumentOutOfRangeException(nameof(take));
        if(skip < 0)
            throw new ArgumentOutOfRangeException(nameof(skip));
        
        return Iterator();

        IEnumerable<T> Iterator()
        {
            int takeCount = 0;
            int skipCount = 0;
            foreach(var item in source)
            {
                if(takeCount < take)
                {
                    yield return item;
                    ++takeCount;
                } else if(skipCount < skip)
                {
                    ++skipCount;
                }

                // reset di entrambi
                if(takeCount == take && skipCount == skip)
                {
                    takeCount = 0;
                    skipCount = 0;
                }
            }
        }
    
    }
}
