using System.Collections.Generic;

namespace Esercizio1;

public static class Esercizio1
{
    public static IEnumerable<T[]>Windowed<T>(this IEnumerable<T> source, int size)
    {
        if(source == null)
            throw new ArgumentNullException(nameof(source));

        if(size <= 0)
            throw new ArgumentOutOfRangeException(nameof(size));
            
        return Iterator();

        IEnumerable<T[]> Iterator()
        {
            var queue = new Queue<T>(size);
            foreach(var item in source)
            {
                queue.Enqueue(item);
                if(queue.Count == size)
                {
                    yield return queue.ToArray();
                    queue.Dequeue();
                }
            }
        }

    }
}
