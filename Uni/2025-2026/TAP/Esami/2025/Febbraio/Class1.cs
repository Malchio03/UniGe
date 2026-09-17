namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T>MyTake<T>(this IEnumerable<T> source, int count)
    {
        if(source == null)
            throw new ArgumentNullException(nameof(source));

        if(count < -1)
            throw new ArgumentOutOfRangeException(nameof(count));

        return Iterator();

        IEnumerable<T> Iterator()
        {
            if(count == 0)
                yield break;

            int contatore = 0;
            
            foreach(var item in source)
            {
                if(contatore < count)
                {
                    yield return item;
                    contatore++;
                }

                if(count == -1)
                    yield return item;
            }
        }
    }
}
